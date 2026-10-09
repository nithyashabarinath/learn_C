/* REQUIREMENT: Input a positive integer and print the Fibonacci series up to that number
DESIGN:
List of Variables: n (input number), first (first term), second (second term), next (next term)
   1.Get an input number from the user
   2.Initialize first to 0 and second to 1
   3.Print first and second
   4.For each number from 2 to n, calculate next as the sum of first and second, print next, and update first and second
TEST CASES:
   1. Input: 5, Output: "0 1 1 2 3"
   2. Input: 10, Output: "0 1 1 2 3 5 8 13 21 34"
*/
#include <stdio.h>
int main()
{
    int n, first = 0, second = 1, next, i;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Fibonacci series up to %d:\n", n);
    for (i = 0; i < n; i++)
    {
        if (i <= 1)
            next = i;
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
    return 0;
}