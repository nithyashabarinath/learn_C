/*REQUIREMENT:C program that uses an array to find the second smallest element
               in a list of numbers.
DESIGN:
List of Variables: 
arr, n (size of array), smaller (smallest element), second_smaller (second smallest element), found_second (flag to indicate if second smallest element is found)
  1. Get the size of the array from the user.
  2. Get the elements of the array from the user.
  3. Find the smallest element in the array.
  4. Find the second smallest element in the array.
  5. Print the second smallest element.
TEST CASES:
- Input: [3, 1, 4, 1, 5] -> Output: 3
- Input: [2, 2, 2, 2] -> Output: -1 (no second smallest)
- Input: [1, 2, 3, 4, 5] -> Output: 2*/

#include <stdio.h>
int main()
{
   int n;
   printf("enter the size of array :");
   scanf("%d",&n);
   int arr[n];
   printf("\nEnter the elements of array :");
   for(int i=0;i<n;i++)
   {
      scanf("%d", &arr[i]);
   }
   int smaller = arr[0]; 
   for(int j=1;j<n;j++)
   {
       if(arr[j] < smaller)
       {
           smaller = arr[j];
       }
   }
   int second_smaller = -1;
   int found_second = 0; 
   for(int j=0;j<n;j++)
   {
       if(arr[j] == smaller)
       {
           continue; 
       }
        if(found_second == 0)
       {
           second_smaller = arr[j];
           found_second = 1;
       }
       else if(arr[j] < second_smaller)
       {
           second_smaller = arr[j];
       }
   } 
   printf("The second smallest element in the array is %d\n", second_smaller);
   return 0;
}