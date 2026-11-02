

/*REQUIREMENT: Input a positive integer and check for the repeating digits.
DESIGN:
  List of Variables: 
   number,freq[10] - to store the frequency of each digit from 0 to 9 ,i - loop counter.

TEST CASES:
  Input: 1234567890
  Output: 
  Digit  Count
    0      1
    1      1
    2      1
    3      1
    4      1
    5      1
    6      1
    7      1
    8      1
    9      1

   Input: -1234567890
   

   Input: -12345678901234567890
   Output:
   Digit Count
     0     2
     1     2
     2     2
     3     2
     4     2
     5     2
     6     2
     7     2
  
*/


#include <stdio.h>
void countDigits(int number, int *freq);


int main(void)
{
    int number, i;
    int freq[10] = {0};                 
    printf("Enter an integer: ");
    scanf("%d", &number);
    printf("\nCounting the digits of %d...\n", number);
    countDigits(number, freq);
    printf("\nDigit  Count\n");
    for (i = 0; i <= 9; i++) 
    {
        printf("  %d      %d\n", i, freq[i]);
    }
    return 0;
}

void countDigits(int number, int *freq)
{
    long long n = number;                
    int digit;

    if (n < 0)
     {
        n = -n;                          
    }

    do
     {
        digit = (int)(n % 10);           
        freq[digit]++;                   
        n = n / 10;                      
    } while (n > 0);
}