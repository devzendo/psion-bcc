/^[^#]/{
name = $1
call = $2
regs = $3
ret = $4
stkoff = 4
nfn = split (call, fn, ",") ;
fname = "epoc" fn[1] fn[2] ".s"
nosave= "[a-d][xhl]|bp";	/* Registers not to save */
print "Generating: " name
  /* Define the function */
  print "export _" name >fname;
  print "_" name ":" >fname;
  print "push bp" >fname
  print "mov bp,sp" >fname
  /* Set ah to sub function number */
  if (nfn > 1) print "mov ah,#$" fn[2] >fname;
  narg = split (regs, nreg, ",");
  /* Save any registers */
  for (i = 1; i<= narg; i++) {
    if (!match (nreg[i], nosave)) print "push " nreg[i] >fname;
  }
  /* Copy arguments to registers */
  for (i = 1; i<= narg; i++) {
    printf ("mov %s,$%X[bp]\n", nreg[i], stkoff) >fname;
    stkoff += 2;
  }
  /* Call the function */
  print "int $" fn[1] >fname;
  /* Transfer any return value */
  if (ret && ret != "ax") {
    print "jc error" >fname;
    print "mov ax," ret >fname;
    print "error:" >fname
  }
  /* Restore registers */
  for (i = narg; i > 0; i--) 
  	if (!match (nreg[i],nosave))print "pop " nreg[i] >fname;
  print "pop bp" >fname
  print "ret" >fname;
  close (fname);  
}
