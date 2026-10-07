/*REQUIREMENT : Write a function in C that takes an array of integers and its size, 
         and returns the second largest element.  
         Constraints: ● Do not sort the array. ● Assume the array has at least two distinct elements. 
DESIGN: 
List of variables: n (size of array), arr (array of integers), larger, second_larger
1. Read the size of the array into variable n and read the elements of the array into arr.
2. After initialising req variables iterate through the array arr and compare each element with larger.
3. If the current element is greater than larger, update larger and update second larger.
4. Print the second largest element.
 TEST CASES:
Input: 5, arr = [3, 1, 4, 2, 5]  output: 4
Input: 6, arr = [10, 20, 30, 40, 40, 60]  output: 40
Input: 4, arr = [11, 12, 13, 13]  output: 12
 */

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
   
   int larger =0;
   int second_larger=0;
   
   for(int j=0;j<n;j++)
   {
       if(arr[j]>larger)
     {
       second_larger=larger;
       larger=arr[j];
     }else if((arr[j]!=larger) && (arr[j]>second_larger))
     {
       second_larger = arr[j];
     }
   }
     printf("The second largest element in the array is %d",second_larger);
   return 0;
}