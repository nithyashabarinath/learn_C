
// C program to print star pattern
#include <stdio.h>

int main()
{  int rows,i,space,star;
   printf("Enter the number of rows for the star pattern :");
   scanf("%d",&rows);
   for(i=1;i<=rows;i++)
   {
     for(space=1;space<=(rows-i);space++)
     { 
         printf(" ");
     }
     for(star=1;star<=i;star++)
     {
         printf("* ");
     }
     printf("\n");
   }
    return 0;
}