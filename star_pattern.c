
/* C program to print star pattern
REQUIREMENT: Input the number of rows and print a star pattern      
DESIGN:
List of Variables: rows (input number of rows), i (loop variable for rows), space (loop variable for spaces), star (loop variable for stars)
   1.Get the number of rows from the user
   2.For each row, print the required number of spaces followed by the required number of stars
TEST CASES:
   1. Input: 5, Output: 
        *
       * *
      * * *
     * * * *
    * * * * *                  
     */
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