/*Q11: Convert an integer into a string of characters, including a minus sign for negative numbers using strings, loops, operators.
 
  ASCII: digit characters are stored as consecutive numbers.
        '0' = 48   '1' = 49   ...   '9' = 57
   Adding a digit's value to '0' gives its character:
        '0' + 7 = 48 + 7 = 55 = '7'
 
DESIGN:
    The last digit of a number is  number % 10,  and removing it is
    number / 10. Repeating that peels off digits RIGHT to LEFT:
       1234 % 10 = 4  -> 1234 / 10 = 123
         123 % 10 = 3  ->  123 / 10 = 12
         12 % 10 = 2  ->   12 / 10 = 1
           1 % 10 = 1  ->    1 / 10 = 0   (stop)
    The digits come out backwards (4 3 2 1), so we store them in a
    temporary array and then copy them into the string in reverse order.
 
  Special cases:
    - Negative number: remember it was negative, work with the positive
     value, and put '-' at the front of the string.
    - Zero: a do-while loop runs at least once, so 0 correctly gives "0".
 

    - We use 'long long' for the working value because turning the
      smallest int (-2147483648) positive does not fit in a normal int.
 */

#include <stdio.h>

int main(void)
{
    int number;                  /* what the user types */
    long long n;                 /* working copy used for the maths */
    char digits[12];             /* digits in reverse order (max 10 digits) */
    char str[13];                /* result: sign + 10 digits + '\0' */
    int count = 0;               /* how many digits we have */
    int negative = 0;            /* 1 if the number is below zero */
    int i, j = 0, d;

    printf("=== Integer to String ===\n\n");

    /* Step 1: read the number; scanf returns 1 when it read an int */
    printf("Enter a whole number: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input! Please enter a whole number.\n");
        return 1;                /* non-zero means the program ended with an error */
    }

    printf("\nYou entered the number: %d\n\n", number);

    /* Step 2: if negative, remember that and work with the positive value */
    n = number;
    if (n < 0) {
        negative = 1;
        n = -n;
        printf("  [debug] number is negative, working with %lld\n", n);
    }

    /* Step 3: peel off digits from the right.
       do-while runs the body first, so the number 0 still gives one digit. */
    do {
        d = (int)(n % 10);                   /* the last digit */
        digits[count] = (char)('0' + d);     /* digit value -> digit character */
        printf("  [debug] digit %d -> character '%c' (ASCII %d)\n",
               d, digits[count], digits[count]);
        n = n / 10;                          /* drop the last digit */
        count++;
    } while (n > 0);

    /* Step 4: build the final string */
    if (negative) {
        str[j] = '-';
        j++;
    }
    for (i = count - 1; i >= 0; i--) {       /* reverse order: 4 3 2 1 -> 1 2 3 4 */
        str[j] = digits[i];
        j++;
    }
    str[j] = '\0';                           /* end marker makes it a proper string */

    /* Step 5: show the result */
    printf("\nResulting string: \"%s\"\n", str);
    printf("(The string has %d character(s).)\n", j);

    return 0;
}
