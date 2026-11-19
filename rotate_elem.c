/*Q23: Rotate the elements of an array by n positions, left or right.
      Elements that fall off one end reappear at the opposite end.
 
  Concepts used: arrays, loops, modulus operator (%).
 
  Idea:
    Rotating an array of size 'size' by 'size' positions brings it back to
   where it started. So rotating by n is the same as rotating by (n % size).
    This is why the program works for ANY n, even n larger than the array.
 
   Using a temporary array 'result' and a rotation amount r = n % size:
      Left  rotation: element at position i moves to (i - r), wrapping around.
                      Same as: result[i] = arr[(i + r) % size]
     Right rotation: element at position i moves to (i + r), wrapping around.
                      Same as: result[(i + r) % size] = arr[i]
 
  Example:  arr = 1 2 3 4 5
            left  by 2 -> 3 4 5 1 2
            right by 2 -> 4 5 1 2 3
            left  by 7 -> same as left by 2 (because 7 % 5 = 2)
 */

#include <stdio.h>

#define MAX_SIZE 100   /* largest array size we allow */


void rotate(int arr[], int size, int n, char dir);
void printArray(int arr[], int size);


int main(void)
{
    int arr[MAX_SIZE];
    int size, n, i;
    char dir;

    printf("=== Rotate Array ===\n\n");

    /* Step 1: read the size, and make sure it is valid */
    printf("Enter the size of the array (1 to %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size! Please run again with a size between 1 and %d.\n", MAX_SIZE);
        return 1;                       /* non-zero means the program ended with an error */
    }

    /* Step 2: read the elements */
    printf("Enter %d integers:\n", size);
    for (i = 0; i < size; i++) {
        printf("  arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    /* Step 3: read how many positions to rotate (must not be negative) */
    printf("Enter number of positions to rotate (n >= 0): ");
    scanf("%d", &n);
    if (n < 0) {
        printf("n cannot be negative. Use the direction (L/R) to choose the side.\n");
        return 1;
    }

    /* Step 4: read the direction.
       The space before %c tells scanf to skip the leftover Enter key. */
    printf("Enter direction (L for left, R for right): ");
    scanf(" %c", &dir);

    if (dir != 'L' && dir != 'l' && dir != 'R' && dir != 'r') {
        printf("Invalid direction! Please enter L or R.\n");
        return 1;
    }

    /* Step 5: show the original array */
    printf("\nOriginal array: ");
    printArray(arr, size);

    /* Step 6: rotate (the array is passed by address, so arr itself changes) */
    rotate(arr, size, n, dir);

    /* Step 7: show the result */
    printf("\nRotated array : ");
    printArray(arr, size);

    return 0;
}

/* ---------- Function definitions ---------- */

/*
 * rotate: rotates arr[] by n positions.
 * dir is 'L'/'l' for left or 'R'/'r' for right.
 */
void rotate(int arr[], int size, int n, char dir)
{
    int result[MAX_SIZE];            /* temporary storage for the new order */
    int r = n % size;                /* effective rotation: n may be bigger than size */
    int i;

    printf("  [debug] n = %d, size = %d, so effective rotation = %d %% %d = %d\n",
           n, size, n, size, r);

    for (i = 0; i < size; i++) {
        if (dir == 'L' || dir == 'l') {
            /* Left: the element r places to the right comes into position i.
               The % wraps the index back to the start when it passes the end. */
            result[i] = arr[(i + r) % size];
            printf("  [debug] left : result[%d] = arr[%d] = %d\n",
                   i, (i + r) % size, result[i]);
        } else {
            /* Right: the element at i moves r places to the right,
               and the % wraps it back to the start when it passes the end. */
            result[(i + r) % size] = arr[i];
            printf("  [debug] right: arr[%d] = %d goes to result[%d]\n",
                   i, arr[i], (i + r) % size);
        }
    }

    /* Copy the rotated result back into the original array */
    for (i = 0; i < size; i++) {
        arr[i] = result[i];
    }
}

/*
 * printArray: prints the elements separated by spaces.
 */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

