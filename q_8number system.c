/*REQUIREMENT : Get an input decimal number and convert to another number system with base 2,base 8 or base 16. 
              Write a function to perform the conversion and return the converted value as a string. 
                    
DESIGN:    
        List of variables: num (input decimal number), base (target base), result (converted value as string)
        1. Read the input decimal number into num.
        2. Read the target base (2, 8, or 16) into base.
        3. Call the convertBase function with num, base, and result as arguments.
        4. In the convertBase function:
            a. Initialize an empty string temp to store the digits in reverse order.
            b. Use a loop to repeatedly divide num by base and store the remainder in temp.
            c. If the remainder is less than 10, convert it to a character ('0' + remainder).
            d. If the remainder is 10 or greater, convert it to a character ('A' + (remainder - 10)).
            e. Continue until num becomes 0.      
TEST CASES:  
Input: 15, Base: 2 -> Output: 1111
Input: 15, Base: 8 -> Output: 17
Input: 15, Base: 16 -> Output: F
*/




#include <stdio.h>

#define RESULT_SIZE 70

void convertBase(int num, int base, char result[]);
int main(void)
{
    int num, base;
    char result[RESULT_SIZE];
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    printf("Enter the target base (2 to 16): ");
    scanf("%d", &base);
    printf("\nConverting %d to base %d...\n", num, base);
    convertBase(num, base, result);
    printf("\n%d in base %d = %s\n", num, base, result);
    return 0;
}

void convertBase(int num, int base, char result[])
{
    char temp[RESULT_SIZE];              /* digits in the order found (reversed) */
    long long n = num;                   /* working copy */
    int count = 0;                       /* how many digits found so far */
    int negative = 0;
    int rem, i, j = 0;

    if (n < 0) 
    {
        negative = 1;
        n = -n;                          /* work with the positive value */
    }
    do {
        rem = (int)(n % base);

        if (rem < 10) 
        {
            temp[count] = (char)('0' + rem);         
        } else 
        {
            temp[count] = (char)('A' + (rem - 10));  
        }

        printf("  [debug] %lld / %d : remainder %d -> '%c'\n",
               n, base, rem, temp[count]);

        n = n / base;
        count++;
    } while (n > 0);
    if (negative) 
    {
        result[j] = '-';
        j++;
    }
    for (i = count - 1; i >= 0; i--) 
    {
        result[j] = temp[i];
        j++;
    }
    result[j] = '\0';                   
}
