/*REQUIREMENT : Write a program to check whether the given number is even or odd.
DESIGN: 
lIST OF VARIABLES: i (input integer)
        1. Read an integer from the user.(i)
        2. Check if the number is divisible by 2.(divisibility test)
        3. If yes, print that it is even; otherwise, print that it is odd.
TEST CASES:
Input: 48 output: 4 is an even number
Input: -67 output: -67 is an odd number
*/

# include <stdio.h>

int main()
{
   int i;
   printf("Enter an integer value:");
   scanf("%d",&i);

   if(i%2==0)
   {
        printf("\n%d is an even number", i);
   }
    else
 {
        printf("\n%d is a odd number", i);
   }
   return 0;
}
