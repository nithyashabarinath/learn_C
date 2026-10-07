#include <stdio.h>

void printBits(int num) 
{
   int totalBits = sizeof(int) * 8;
    printf("Binary representation: ");
    for (int i = totalBits - 1; i >= 0; i--)
    {
        int bit = (num >> i) & 1;
        printf("%d", bit);
        if (i % 8 == 0) 
        {
            printf(" ");
        }
    }
    printf("\n");
}

int main()
 {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    printBits(num);
    return 0;
}