#include <stdio.h>
#include <ctype.h>



short chksum( unsigned char *a, int len) {
  short sum = 0;

  for ( ; len > 0 ; len--)
    sum += *a++;
  return sum;
}

unsigned char digval(char c)
{
  if (c>='0' && c<='9')
    return c-'0';
  return c-'A'+10;
}

void main()
{
unsigned char cs[2000];
int count = 0;
unsigned char c1,c2;
  do {
    c1 = getchar();
    if (feof(stdin))
      break;
    if (isspace(c1))
      continue;
    c2 = getchar();
    if (feof(stdin))
      break;
    cs[count]= digval(c1) * 16 + digval(c2);
    count++;
  }
  while (!feof(stdin));
  printf("checksum is 0x%04X\n", chksum(cs,count));
}

