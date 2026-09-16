 #include <stdio.h>
void swap(int *x,int*y);

 int main()
{int num1,num2;
printf("Enter two integers for swapping:\n");
scanf("%d %d", &num1, &num2);
swap(&num1,&num2);
printf("After swapping:\n %d  %d", num1, num2);
return 0;
}
void swap(int *x,int*y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
