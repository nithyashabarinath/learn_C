/*C program to determine whether the number is prime or not
REQUIREMENT: Input a positive integer and check if it is prime 
DESIGN:
List of Variables: n (input number), i (loop variable), flag (prime check indicator)
   1.Get an input number from the user 
   2.IF the number is 1, print "1 is neither prime nor composite."
   3.ELSE, check if the number is divisible by any number from 2 to n/2
   4.IF it is divisible, set flag to 1 and break the loop
   5.IF flag is still 0 after the loop, print "n is a prime number."
TEST CASES:
   1. Input: 7, Output: "7 is a prime number."
   2. Input: 42, Output: "42 is not a prime number."
   3. Input: 1, Output: "1 is neither prime nor composite." */
#include <stdio.h>
int main()
{
    int n, i, flag = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (i = 2; i <= n / 2; ++i)
    {
    if (n == 1)
      {
        printf("1 is neither prime nor composite.");
        continue;
      } 
    else if (n % i == 0)
      {
            flag = 1;
            break;
      }
    }
    if (flag == 0)
    {
            printf("%d is a prime number.", n);
        else
            printf("%d is not a prime number.", n);
    }

    return 0;
}