
/* Very Simple "Hello World" program using console */
/* Written by S.N. Henson and released into Public Domain */

int tarea[4];

main ()
{
int tmpfd;
int tmparg1, tmparg2;
FilConnect (0,0); /* Connect to file server */

tmpfd = IoOpen ("CON:", -1, 0); /* Open Console */

tmparg1 = 20;
tmparg2 = 0;
IoWithWait (tmpfd, 7, &tmparg1, &tmparg2); /* Reset Compatbility Mode */

tarea[0] = 0;
tarea[1] = 0;
tarea[2] = 75;
tarea[3] = 11;
tmparg1 = 5;

IoWithWait (tmpfd, 7, &tmparg1, tarea); /* Resize Console */

tmparg1 = 9;
tmparg2 = 1;
IoWithWait (tmpfd, 7, &tmparg1, &tmparg2); /* Cursor On */

tarea[0] = 0x4004;
tarea[1] = 0x10;
tmparg1 = 0x11;
IoWithWait (tmpfd, 7, &tmparg1, tarea); /* Set Font and style */

IoWrite (tmpfd, "Hello World\r\n", 13); /* Output Message */

IoRead (tmpfd, tarea, 4);              /* Wait For Keypress */

IoClose (tmpfd);                      /* Close Console */

return (0);
}
