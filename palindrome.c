/*Q12: Check whether a string is a palindrome using loops, control statements, strings, operators.
 
 DESIGN:
 A palindrome is a string that reads the same forwards and backwards. To check if a string is a palindrome.
 we can use two pointers: one starting at the beginning of the string (left) and the other starting at the end of the string (right). 
 We compare the characters at these two positions:
  step 1:left  starts at the first character
  step 2:right starts at the last character
  step 3:Compare str[left] with str[right]:
        - if they differ, it is NOT a palindrome: stop straight away
        - if they match, move inwards (left++, right--) and compare again
  step 4:When left meets or passes right, every pair matched, so it is a palindrome.
 
       r a c e c a r
      ^           ^      r == r   -> match, move inwards
          ^       ^        a == a   -> match
            ^   ^          c == c   -> match
              ^            left meets right: done, it is a palindrome
 
  The comparison is exact: letters must match in case ('R' is not 'r')
 and spaces and symbols count too. "racecar" is a palindrome, but
  "Racecar" and "nurses run" are not.
(To ignore case we can compare tolower(str[left]) and
  tolower(str[right]) using <ctype.h>.)
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100   /* room for 99 characters plus the end marker '\0' */

int main(void)
{
    char str[MAX_LEN];
    int left, right, len;
    int isPalindrome = 1;                /* assume yes until a mismatch is found */

    printf("=== Palindrome Checker ===\n\n");

    /* Step 1: read a whole line (fgets keeps spaces in the text) */
    printf("Enter a string: ");
    if (fgets(str, MAX_LEN, stdin) == NULL) {
        printf("No input received.\n");
        return 1;                        /* non-zero means the program ended with an error */
    }

    /* Step 2: remove the Enter key ('\n') that fgets stores at the end */
    str[strcspn(str, "\n")] = '\0';

    len = (int)strlen(str);              /* number of characters before '\0' */
    printf("\nYou entered: \"%s\" (%d characters)\n\n", str, len);

    /* Step 3: compare characters from both ends, moving inwards */
    left = 0;
    right = len - 1;

    while (left < right) {
        printf("  [debug] compare str[%d]='%c' with str[%d]='%c'\n",
               left, str[left], right, str[right]);

        if (str[left] != str[right]) {
            isPalindrome = 0;            /* found a mismatch */
            printf("  [debug] mismatch, stopping early\n");
            break;
        }

        left++;                          /* move the left pointer one step right */
        right--;                         /* move the right pointer one step left */
    }

    /* Step 4: report the verdict */
    printf("\n");
    if (isPalindrome) {
        printf("Result: \"%s\" IS a palindrome.\n", str);
    } else {
        printf("Result: \"%s\" is NOT a palindrome.\n", str);
    }

    return 0;
}