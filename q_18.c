/*
REQUIREMENT:Extract n bits, starting from a given bit position, from an integer.
 Making use of bitwise operators (& >> <<).Bit positions are counted from the RIGHT, starting at 0
"n bits starting at position pos" means bits pos, pos+1, ... pos+n-1.
 DESIGN:
1.	Shift the number RIGHT by pos, so the bits we want land at the right-hand end:               num >> pos     170 >> 2  =  0010 1010
2. Build a MASK with n ones on the right:   (1 << n) - 1
     n = 4  ->  0000 1111
3. AND them. Only the bits where the mask has a 1 survive, so every other bit is wiped out and cannot affect the answer:
       0010 1010 & 0000 1111  =  0000 1010  =  10
 4.We use 'unsigned int' for the bit work because shifting signed numbers can behave unexpectedly (a negative number may be shifted in with 1s).
 TEST CASES:
Input: 170, pos: 2, n: 4, Output: 10
 */

#include <stdio.h>

#define INT_BITS 32   /* we assume int is 32 bits wide (true on most systems) */

void printBinary(unsigned int num);

int main(void)
{
    int input;                           /* what the user types */
    unsigned int num, shifted, mask, result;
    int pos, n;

    printf("=== Extract n Bits From a Number ===\n\n");
    printf("Enter an integer: ");
    scanf("%d", &input); 
    printf("Enter starting bit position (0 = rightmost bit): ");
    scanf("%d", &pos);
    printf("Enter number of bits to extract (n): ");
    scanf("%d", &n);

    if (pos < 0 || n < 1 || pos + n > INT_BITS) 
    {
        printf("Invalid input! Position must be >= 0, n must be >= 1,\n");
        printf("and position + n must not be more than %d.\n", INT_BITS);
        return 1;                        /* non-zero means the program ended with an error */
    }

    num = (unsigned int)input;           /* copy into an unsigned variable */

    printf("\nNumber = %d\n  ", input);
    printBinary(num);
    shifted = num >> pos;
    printf("\n  [debug] after shifting right by %d:\n  ", pos);
    printBinary(shifted);
    if (n == INT_BITS) 
    {
        mask = 0xFFFFFFFFu;              /* all 32 bits set */
    } else 
    {
        mask = (1u << n) - 1u;           /* n ones on the right */
    }
    printf("  [debug] mask (n = %d ones):\n  ", n);
    printBinary(mask);
    result = shifted & mask;
    printf("\nExtracted bits (bits %d to %d):\n  ", pos, pos + n - 1);
    printBinary(result);
    printf("Result = %u\n", result);

    return 0;
}


void printBinary(unsigned int num)
{
    int bit;
    for (bit = INT_BITS - 1; bit >= 0; bit--) 
    {
        printf("%u", (num >> bit) & 1u);     
        if (bit % 8 == 0 && bit != 0) {
            printf(" ");
        }
    }
    printf("\n");
}

