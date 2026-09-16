# include <stdio.h>
void addvalue(int *ptr,int size)
{
    for(int i=0;i<size;i++)
    { 
    *ptr=*ptr+55;
    ptr++;
    }
}
int main()
{
    int k;
    printf("Enter the size of array: ");
    scanf("%d", &k);
    int arr[k];
    printf("\nEnter the elements of array: ");
    for(int i=0;i<k;i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nthe original array: ");
    for(int i=0;i<k;i++)
    {
        printf("%d ", arr[i]);
    }
addvalue(arr, k);
    printf("\nthe modified array: ");
    for(int i=0;i<k;i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}