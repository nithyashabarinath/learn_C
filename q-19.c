/*Q19: 
Replace n bits of a number, starting at a given position, with the
corresponding n bits of a second number using bitwise operators (& | ~ << >>).
 
 Bit positions are counted from the RIGHT, starting at 0:
 
       bit:  7 6 5 4 3 2 1 0
       value 1 0 1 0 1 0 1 0      <- the number 170 (shown with 8 bits)
      "n bits starting at position pos" means bits pos, pos+1, ... pos+n-1.
 "Corresponding bits" means the SAME positions in the second number.
 Example: pos = 2, n = 4  ->  bits 5 4 3 2 of both numbers.
 
 DESIGN:
    1. Build a MASK: 1s exactly in the n positions we care about.
           n 1s on the right :  (1 << n) - 1        e.g. n = 4 -> 0000 1111
           move them to pos  :  ... << pos          e.g. pos = 2 -> 0011 1100
    2. Clear those bits in the first number:     a & ~mask
           (~mask has 0s in the chosen positions and 1s everywhere else,
            so every other bit of a is kept exactly as it was)
    3. Cut those bits out of the second number:  b & mask
    4. Join the two parts with OR:
           result = (a & ~mask) | (b & mask)
 
 we use 'unsigned int' for the bit work because shifting and flipping
 signed numbers can behave unexpectedly.
 */

#include <stdio.h>

#define INT_BITS 32   


void printBinary(unsigned int num);


int main(void)
{
    int inputA, inputB;                  /* what the user types */
    unsigned int a, b, mask, cleared, piece, result;
    int pos, n;

    printf("=== Replace n Bits of a Number ===\n\n");

    /* Step 1: read the two numbers */
    printf("Enter first integer (bits will be replaced) : ");
    scanf("%d", &inputA);
    printf("Enter second integer (bits are copied from) : ");
    scanf("%d", &inputB);

    /* Step 2: read the start position and the number of bits */
    printf("Enter starting bit position (0 = rightmost bit): ");
    scanf("%d", &pos);
    printf("Enter number of bits to replace (n): ");
    scanf("%d", &n);

    /* Step 3: make sure the chosen bits fit inside a 32-bit number */
    if (pos < 0 || n < 1 || pos + n > INT_BITS) {
        printf("Invalid input! Position must be >= 0, n must be >= 1,\n");
        printf("and position + n must not be more than %d.\n", INT_BITS);
        return 1;                        /* non-zero means the program ended with an error */
    }

    a = (unsigned int)inputA;            /* copy into unsigned variables */
    b = (unsigned int)inputB;

    /* Step 4: show both numbers */
    printf("\nFirst number  = %d\n  ", inputA);
    printBinary(a);
    printf("Second number = %d\n  ", inputB);
    printBinary(b);

    /* Step 5: build the mask.
       Shifting a 32-bit number left by 32 is not allowed in C, so the
       case n = 32 (all bits) is handled separately. */
    if (n == INT_BITS) {
        mask = 0xFFFFFFFFu;              /* all 32 bits set */
    } else {
        mask = (1u << n) - 1u;           /* n ones on the right */
    }
    mask = mask << pos;                  /* slide them to the chosen position */

    printf("\n  [debug] mask (bits %d to %d):\n  ", pos, pos + n - 1);
    printBinary(mask);

    /* Step 6: clear the chosen bits in the first number */
    cleared = a & ~mask;
    printf("  [debug] first number with those bits cleared:\n  ");
    printBinary(cleared);

    /* Step 7: take the same bits from the second number */
    piece = b & mask;
    printf("  [debug] bits taken from the second number:\n  ");
    printBinary(piece);

    /* Step 8: join them */
    result = cleared | piece;

    /* Step 9: show the result */
    printf("\nResult = %d\n  ", (int)result);
    printBinary(result);

    return 0;
}


void printBinary(unsigned int num)
{
    int bit;
    for (bit = INT_BITS - 1; bit >= 0; bit--) {
        printf("%u", (num >> bit) & 1u);     /* shift bit to the right end, keep it */
        if (bit % 8 == 0 && bit != 0) {
            printf(" ");
        }
    }
    printf("\n");
}
