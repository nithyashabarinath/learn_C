/*REQUIREMENT: Input a positive integer and check if it is a perfect number
DESIGN:
List of Variables: n (input number), sum (sum of divisors), divisor (current divisor being checked)
   1. Get an input number from the user
   2. Initialize sum to 0
   3. For each number from 1 to n/2, check if it is a divisor of n
   4. If it is a divisor, add it to sum
   5. If sum equals n, print that it is a perfect number; otherwise, print that it is not
TEST CASES:
   1. Input: 6, Output: "6 is a perfect number."
   2. Input: 28, Output: "28 is a perfect number."
   3. Input: 12, Output: "12 is not a perfect number."
*/
#include<stdio.h>
int perfect(int num);
int main()
{
    int n,summ;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    summ = perfect(n);
    if (summ == n)
    {
        printf("%d is a perfect number.", n);
    }
    else
    {
        printf("%d is not a perfect number.", n);
    }
    return 0;
}
int perfect(int num)
 {
    int sum = 0;
    for (int divisor= 1; divisor <= num / 2; divisor++)
     {
     if (num % divisor == 0)
     {
        sum += divisor;
     }
    }
     return sum;
     
 }