/*REQUIREMENT:
DESIGN:
List of Variables: num1, num2, res
  1. Get two positive integers from the user
  2.. Call the gcd function with the two numbers.
  3. Print the result.
Function used: gcd (2 arguments)
   1. When the remainder drops to zero,the function stops calling itself.
   2. returns calculated gcd to the main function.
   3. EUCLIDEAN ALGORITHM- GCD of two numbers divides their difference or their remainder and
   the program continually scales down the numbers until they cannot be divided any further.
TEST CASES:
   1. Input: 12, 18, Output: 6
   2. Input: 100, 25, Output: 25*/


#include <stdio.h>
int gcd(int a, int b);
int main() 
{
    int num1, num2,res=0;
    printf("Enter two positive integers: ");
    scanf("%d %d",&num1,&num2);
    res = gcd(num1, num2);
    printf("The GCD of %d and %d is: %d\n", num1, num2, res);
    return 0;
}
int gcd(int a, int b) 
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}