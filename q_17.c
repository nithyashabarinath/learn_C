/*Q17
REQUIREMENT: Toggle n bits, starting from a given position, in an integer. Toggle means: 0 becomes 1, and 1 becomes 0 using bitwise operators (^ <<), loops, assignment operators (^=).
 Bit positions are counted from the RIGHT, starting at 0:
 
         bit:  7 6 5 4 3 2 1 0
         value 1 0 1 0 1 0 1 0      <- the number 170 (shown with 8 bits)
 
  "n bits starting at position pos" means bits pos, pos+1, ... pos+n-1.
  Example: pos = 2, n = 4  ->  bits 5 4 3 2.
 
DESIGN:
    The XOR operator (^) flips a bit when the other bit is 1:
           x ^ 1  =  flipped x         x ^ 0  =  x (unchanged)
    So to flip ONE bit at position p, XOR the number with (1 << p).
   We do that for every position pos .. pos+n-1 using a loop:
           num ^= (1u << (pos + i));        <- same as num = num ^ (...)
   All other bits are XORed with 0, so they stay exactly as they were.
 Shortcut (same result, no loop): build a mask with n ones, slide it to pos, and do one XOR:   num ^= ((1u << n) - 1u) << pos;
 We use 'unsigned int' for the bit work because shifting signed numbers can behave unexpectedly

Step 1: read the number
 Step 2: read the start position and the number of bits 
 Step 3: make sure the chosen bits fit inside a 32-bit number 
 Step 4: show the number before the toggle 
 Step 5: flip the bits one at a time, from position pos upwards 
 Step 6: show the result 
  TEST CASE:  
  INPUT:170  binary equivalent-10101010
  (from the right )pos = 2, n = 4, 
  output:150  10010110
 */

#include <stdio.h>

#define INT_BITS 32   /* we assume int is 32 bits wide (true on most systems) */


void printBinary(unsigned int num);

int main(void)
{
    int input;                           /* what the user types */
    unsigned int num;
    int pos, n, i;

    printf("=== Toggle n Bits of a Number ===\n\n");
    printf("Enter an integer: ");
    scanf("%d", &input);
    printf("Enter starting bit position (0 = rightmost bit): ");
    scanf("%d", &pos);
    printf("Enter number of bits to toggle (n): ");
    scanf("%d", &n);
    num = (unsigned int)input;          
    printf("\nBefore toggle: %d\n  ", input);
    printBinary(num);

   
    printf("\n");
    for (i = 0; i < n; i++) {
        num ^= (1u << (pos + i));        /* XOR with a single 1 flips just that bit */
        printf("  [debug] toggled bit %d:\n  ", pos + i);
        printBinary(num);
    }

  
    printf("\nAfter toggle: %d\n  ", (int)num);
    printBinary(num);

    return 0;
}


void printBinary(unsigned int num)
{
    int bit;
    for (bit = INT_BITS - 1; bit >= 0; bit--) 
    {
        printf("%u", (num >> bit) & 1u);     
        if (bit % 8 == 0 && bit != 0) 
        {
            printf(" ");
        }
    }
    printf("\n");
}