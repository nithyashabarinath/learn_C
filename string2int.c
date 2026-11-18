#include <stdio.h>
#include <string.h>
#include <limits.h>   /* gives us INT_MAX, the largest value an int can hold */

#define MAX_LEN 50   

int main(void)
{
    char str[MAX_LEN];
    int i, digit, next;
    int number = 0;                      

    printf("Enter a number: ");
    fgets(str, MAX_LEN, stdin) == NULL;
    str[strcspn(str, "\n")] = '\0';
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9') 
        {
            printf("Invalid input! '%c' at position %d is not a digit.\n", str[i], i);
            printf("(Only positive whole numbers are handled here.)\n");
            return 1;
        }
    }
    for (i = 0; str[i] != '\0'; i++)
     {
        digit = str[i] - '0';            /* character -> its numeric value */

        if (number > (INT_MAX - digit) / 10)
         {
            printf("Number too large! The biggest allowed value is %d.\n", INT_MAX);
            return 1;
        }

        next = number * 10 + digit;
        printf("  [debug] '%c' -> digit %d : %d * 10 + %d = %d\n",
               str[i], digit, number, digit, next);
        number = next;
    }
    printf("\nInteger value = %d\n", number);
    printf("Check: value * 2 = %lld\n", (long long)number * 2);

    return 0;
}
