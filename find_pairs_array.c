 /*Q25: Find all pairs of elements in an array whose sum equals a target.
 Concepts used: arrays, nested loops, conditional statements.
 
  Idea (brute force with nested loops):
    Take each element arr[i], and compare it with every element that comes
   AFTER it (arr[j], where j starts at i + 1). If arr[i] + arr[j] == target,
    print the pair.
 
  Why j starts at i + 1:
    - It stops an element from being paired with itself (j never equals i).
    - It stops the same pair being printed twice, once as (a, b) and again
      as (b, a).
 
 Example: arr = 1 5 7 -1 5, target = 6
           pairs: (1, 5)  (1, 5)  (7, -1)
          (1 pairs with each of the two 5s, because they are different
            elements at different positions.)
 */

#include <stdio.h>

#define MAX_SIZE 100   /* largest array size we allow */

int main(void)
{
    int arr[MAX_SIZE];
    int n, target, i, j;
    int count = 0;     /* how many pairs we found; 0 means "none" */

    printf("=== Find Pairs With a Given Sum ===\n\n");

    /* Step 1: read the size, and make sure it is valid */
    printf("Enter the size of the array (1 to %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n < 1 || n > MAX_SIZE) {
        printf("Invalid size! Please run again with a size between 1 and %d.\n", MAX_SIZE);
        return 1;                       /* non-zero means the program ended with an error */
    }

    /* Step 2: read the elements */
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        printf("  arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    /* Step 3: read the target sum */
    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("\nLooking for pairs that add up to %d...\n", target);

    /* Step 4: check every possible pair using nested loops */
    for (i = 0; i < n - 1; i++) {            /* first element of the pair */
        for (j = i + 1; j < n; j++) {        /* second element, always after i */

            /* Debug print: shows every comparison being made */
            printf("  [debug] checking arr[%d] + arr[%d] = %d + %d = %d\n",
                   i, j, arr[i], arr[j], arr[i] + arr[j]);

            if (arr[i] + arr[j] == target) {
                printf("  --> Pair found: (%d, %d) at positions %d and %d\n",
                       arr[i], arr[j], i, j);
                count++;                     /* remember that we found one */
            }
        }
    }

    /* Step 5: report the outcome */
    if (count == 0) {
        printf("\nNo pair of elements adds up to %d.\n", target);
    } else {
        printf("\nTotal pairs found: %d\n", count);
    }

    return 0;
}
