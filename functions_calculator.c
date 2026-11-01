/*
 REQUIREMENT: Use functions to evaluate a simple arithmetic expression, given two
     floating point numbers and an operator (+ - * /).
 
 DESIGN:
 List of functions:
       add(), subtract(), multiply(), divide()  - one small function per operation
       calculate()  - the SELECTOR: looks at the operator and calls the right one
 TEST CASES:
 1.  a = 5.0, b = 2.0, op = '+', result = 7.0
 */

#include <stdio.h>
double add(float a, float b);
double subtract( float a, float b);
double multiply(float a, float b);
double divide( float a, float b, int *ok);
double calculate( float a, float b, char op, int *ok);

int main(void)
{
    float a, b, result;
    char op;
    int ok;                           
    printf("Enter first floating-point number : ");
    scanf("%f", &a);
    printf("\n Enter second floating-point number: ");
    scanf("%f", &b); 
    printf("\nEnter operator (+, -, *, /): ");
    scanf(" %c", &op);
    printf("\nCalculating %g %c %g...\n", a, op, b);
    result = calculate(a, b, op, &ok); 
    if (ok) {
        printf("\nResult: %g %c %g = %.4f\n", a, op, b, result);
    } else {
        printf("\nNo result: the calculation could not be completed.\n");
    }

    return 0;
}

double add(float a, float b)
{
    printf("addition\n");
    return a + b;
}

double subtract( float a, float b)
{
    printf("subtraction\n");
    return a - b;
}

double multiply( float a,  float b)
{
    printf(" multiplication\n");
    return a * b;
}
double divide(float a, float b, int *ok)
{
    printf(" division\n");
    if (b == 0.0) 
    {
        printf("  Error: division by zero is not allowed.\n");
        *ok = 0;                       
        return 0.0;
    }
     return a / b;
}
double calculate(float a, float b, char op, int *ok)
{
    double result = 0.0;

    *ok = 1;                  
    switch (op) 
    {
        case '+':
            result = add(a, b);
            break;
        case '-':
            result = subtract(a, b);
            break;
        case '*':
            result = multiply(a, b);
            break;
        case '/':
            result = divide(a, b, ok);
            break;
        default:
            printf("  Error: '%c' is not a valid operator (use + - * /).\n", op);
            *ok = 0;
            break;
    }

    return result;
}
