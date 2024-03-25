#include <stdio.h>
#include <stdlib.h>

int main()
{

int a=1;
switch(a)
{
    case 0:
    printf("Isa\n");
    break;
    case 1:
    printf("Isabel\n");
    break;
}

int i;
for (int i=0; i<21;i++)
{
   if(i==13)
    {
        continue;
    }
    else
     {
        printf ("%d\n",i);
     }
}

int j=0;
for (int j=0; j<40;j++)
{
     if(j% 2!=0)
    {//No divisible by 2
        printf("%d\n",j);
    }
      else
     {
      continue;
     }

}
    return 0;
}
