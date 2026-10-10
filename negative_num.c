/*REQUIREMENT:Rearrange an array so all negative numbers come before all positive
 numbers, keeping the original relative order inside each group.
 Zero is treated as positive.
 
 DESIGN: 
    Pass 1: copy every negative number into temp[], left to right.
    Pass 2: copy every non-negative number (>= 0) into temp[] after them.
   Pass 3: copy temp[] back into the original array.
 Because we always scan left to right, the order inside each group is kept.
 
 TEST CASES: -1  2  -3  4  5  -6   output:   -1  -3  -6  2  4  5
 */

#include <stdio.h>
#define MAX_SIZE 100  
void rearrange(int arr[], int n);
void printArray(int arr[], int n);
int main(void)
{
    int arr[MAX_SIZE];
    int n, i;
    printf("Enter the size of the array (1 to %d): ", MAX_SIZE);
    scanf("%d", &n);     
    printf("Enter %d integers (positive, negative or zero):\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printArray(arr, n);
    rearrange(arr, n);
    printf("\nRearranged array: ");
    printArray(arr, n);
    return 0;
}
void rearrange(int arr[], int n)
{
    int temp[MAX_SIZE];  
    int k = 0;            
    int i;
    for (i = 0; i < n; i++) 
    {
        if (arr[i] < 0) 
        {
            temp[k] = arr[i];
            k++;
        }
    }
    for (i = 0; i < n; i++) 
    {
        if (arr[i] >= 0) 
        {
            temp[k] = arr[i];
            k++;
        }
    }*/
    for (i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) 
    {
    printf("%d ", arr[i]);
    printf("\n");
    }
}
