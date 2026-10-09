/*REQUIREMENT: Input a positive integer and calculate its factorial
DESIGN:
List of Variables: n (input number), i (loop variable), factorial (result)
   1.Get an input number from the user
   2.Initialize factorial to 1
   3.For each number from 1 to n, multiply factorial by that number
   4.Print the result
TEST CASES:
   1. Input: 5, Output: "The factorial of 5 is 120."
   2. Input: 0, Output: "The factorial of 0 is 1."
*/
#include<stdio.h>

int main()
{
    int n, i;
    long long factorial = 1;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    printf("The factorial of %d is %lld.", n, factorial);
    return 0;
}