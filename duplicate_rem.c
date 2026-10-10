/*REQUIREMENT:Write a C program to remove duplicate elements from a given array.(ARRAY)
DESIGN:
List of Variables: 
arr, size (size of array), i, j, k (loop variables)
  1. Get the size of the array from the user.
  2. Get the elements of the array from the user.
  3. Use nested loops to compare each element with the rest of the elements in the array.
  4. If a duplicate is found, shift all subsequent elements to the left to overwrite the duplicate and decrease the size of the array.
  5. Print the modified array without duplicates.
TEST CASES:
- Input: [1, 2, 3, 2, 4, 1] -> Output: [1, 2, 3, 4]
- Input: [5, 5, 5, 5] -> Output: [5]
- Input: [1, 2, 3, 4, 5] -> Output: [1, 2, 3, 4, 5]*/

#include <stdio.h>
int main()
{
    int arr[100];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; i++) 
    {
    for (int j = i + 1; j < size; j++) 
      {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < size - 1; k++)
                {
                arr[k] = arr[k + 1];
                }
                size--;
                j--; 
            }
        }
    }
    printf("\nArray after removing duplicates:\n");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}