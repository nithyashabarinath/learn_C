/*Q20: Swap n bits, starting from a given position, between two integers.
 
  Concepts used: bitwise operators (& | ~ <<), loops, assignment operators.
 
  Bit positions are counted from the RIGHT, starting at 0:
 
       bit:  7 6 5 4 3 2 1 0
        value 1 0 1 0 1 0 1 0      <- the number 170 (shown with 8 bits)

  "n bits starting at position pos" means bits pos, pos+1, ... pos+n-1.
  Example: pos = 2, n = 4  ->  bits 5 4 3 2.
 
  Idea:
    1. Build a MASK: a number with 1s exactly in the n positions we want.
           pos = 2, n = 4  ->  mask = 0011 1100
   2. Cut out those bits from each number:   a & mask    b & mask
   3. Clear those bits in each number:       a & ~mask    b & ~mask
           (~mask flips the mask, so it has 0s in the chosen positions
           and 1s everywhere else, which keeps all the other bits)
   4. Put the other number's bits in:
           a = (a & ~mask) | (bits cut from b)
           b = (b & ~mask) | (bits cut from a)
 
  We use 'unsigned int' for the bit work because shifting and flipping
  signed numbers can behave unexpectedly.
  TEST CASE:
  INPUT: 45  binary equivalent-00101101
  (from the right )pos = 1, n = 2,
   
  Enter first integer : 45
  Enter second integer: 54
    Enter starting bit position (0 = rightmost bit): 1
    Enter number of bits to swap (n): 2
    OUTPUT: 47  binary equivalent-00101111
            52  binary equivalent-00110100
 */

#include <stdio.h>

#define INT_BITS 32   /* we assume int is 32 bits wide (true on most systems) */

/* ---------- Function prototypes ---------- */
void printBinary(unsigned int num);

/* ---------- main ---------- */
int main(void)
{
    int inputA, inputB;                  /* what the user types */
    unsigned int a, b;                   /* the same values, used for bit work */
    int pos, n, i;
    unsigned int mask = 0;
    unsigned int bitsA, bitsB;           /* the bits cut out of a and b */

    printf("=== Swap n Bits Between Two Numbers ===\n\n");

    /* Step 1: read the two numbers */
    printf("Enter first integer : ");
    scanf("%d", &inputA);
    printf("Enter second integer: ");
    scanf("%d", &inputB);

    /* Step 2: read the start position and the number of bits */
    printf("Enter starting bit position (0 = rightmost bit): ");
    scanf("%d", &pos);
    printf("Enter number of bits to swap (n): ");
    scanf("%d", &n);

    /* Step 3: make sure the chosen bits fit inside a 32-bit number */
    if (pos < 0 || n < 1 || pos + n > INT_BITS) {
        printf("Invalid input! Position must be >= 0, n must be >= 1,\n");
        printf("and position + n must not be more than %d.\n", INT_BITS);
        return 1;                        /* non-zero means the program ended with an error */
    }

    a = (unsigned int)inputA;            /* copy into unsigned variables */
    b = (unsigned int)inputB;

    /* Step 4: show the numbers before the swap */
    printf("\nBefore swap:\n");
    printf("  first  = %d\n         ", inputA);
    printBinary(a);
    printf("  second = %d\n         ", inputB);
    printBinary(b);

    /* Step 5: build the mask with 1s in positions pos .. pos+n-1 */
    for (i = 0; i < n; i++) {
        mask |= (1u << (pos + i));       /* set one more bit each time round */
    }
    printf("\n  [debug] mask (bits %d to %d):\n          ", pos, pos + n - 1);
    printBinary(mask);

    /* Step 6: cut out the chosen bits from both numbers */
    bitsA = a & mask;                    /* keeps only the chosen bits of a */
    bitsB = b & mask;                    /* keeps only the chosen bits of b */
    printf("  [debug] chosen bits of first :\n          ");
    printBinary(bitsA);
    printf("  [debug] chosen bits of second:\n          ");
    printBinary(bitsB);

    /* Step 7: clear those bits, then drop in the other number's bits */
    a = (a & ~mask) | bitsB;
    b = (b & ~mask) | bitsA;

    /* Step 8: show the numbers after the swap */
    printf("\nAfter swap:\n");
    printf("  first  = %d\n         ", (int)a);
    printBinary(a);
    printf("  second = %d\n         ", (int)b);
    printBinary(b);

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

