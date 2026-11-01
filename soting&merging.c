/*REQUIREMENT:Merge two sorted arrays into one sorted array, without any sort function.
 DESIGN:
 *   Keep one index for each input array: i for a[], j for b[].
 *   Repeatedly compare a[i] and b[j]:
 *       - copy the smaller one into merged[k] and move that index forward
 *   When one array runs out, copy whatever is left of the other array
 *   (it is already sorted, so it can go in as it is).
 *
 * Example:  a = 1 4 9      b = 2 3 10 11
 *           merged = 1 2 3 4 9 10 11
 */

#include <stdio.h>

//#define MAX_SIZE 50   /* largest size allowed for each input array */

/* ---------- Function prototypes ---------- */
void readSortedArray(int arr[], int n, char name);
void printArray(int arr[], int n);

int main(void)
{    int MAX_SIZE1, MAX_SIZE2;
    int a[MAX_SIZE1], b[MAX_SIZE2];
    int merged[MAX_SIZE1 + MAX_SIZE2];         
    int n1, n2;
    int i = 0, j = 0, k = 0;       
    printf("Enter size of first array %d:  ", MAX_SIZE1);
    scanf("%d", &n1);
    readSortedArray(a, n1, 'a');
    printf("\nEnter size of second array  %d:  ", MAX_SIZE2);
    scanf("%d", &n2);
    readSortedArray(b, n2, 'b');
    printf("\nFirst array : ");
    printArray(a, n1);
    printf("Second array: ");
    printArray(b, n2);
    printf("\nMerging...\n");
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j]) 
        {          
            merged[k] = a[i];
            i++;                      
        } else 
        {
            merged[k] = b[j];
            j++;                      
        }
        k++;                         
    }
    while (i < n1) 
    {
        merged[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        merged[k] = b[j];
        j++;
        k++;
    }
    printf("\nMerged sorted array (%d elements): ", k);
    printArray(merged, k);
    return 0;
}
void readSortedArray(int arr[], int n, char name)
{
    int i;
    printf("Enter %d integers in ASCENDING order:\n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

