/*REQUIREMENT: Define a structure Complex (real + imaginary parts) and write a C
          program that adds two complex numbers and displays the result.

  DESIGN:A complex number is written as  a + bi
         a = real part, b = imaginary part
        Adding two complex numbers means adding the real parts together and the
        imaginary parts together:
       (a + bi) + (c + di) = (a + c) + (b + d)i
  LIST OF VARIABLES:
  - num1, num2, sum: instances of the Complex structure
  - c1, c2, result: parameters and return value for the addComplex function
  TEST CASES:
  - Input: (3.0 + 4.0i) and (1.0 + 2.0i), Output: (4.0 + 6.0i)
  - Input: (5.0 + 0.0i) and (0.0 + 3.0i), Output: (5.0 + 3.0i)
 */
#include <stdio.h>
struct Complex 
{
    float real;   
    float imag;  
};
struct Complex add(struct Complex c1, struct Complex c2);
void displayComplex(struct Complex c);
int main(void)
{
    struct Complex num1, num2, sum;   
    printf("Enter first complex number\n");
    printf("  Real part      : ");
    scanf("%f", &num1.real);          /* & gives scanf the address to store into */
    printf("  Imaginary part : ");
    scanf("%f", &num1.imag);
    printf("Enter second complex number\n");
    printf("  Real part      : ");
    scanf("%f", &num2.real);
    printf("  Imaginary part : ");
    scanf("%f", &num2.imag);
    printf("\nAdding the two numbers...\n");
    sum = add(num1, num2);
    printf("Sum = ");
    displayComplex(sum);
    return 0;                         
}
struct Complex add(struct Complex c1, struct Complex c2)
{
    struct Complex result;
    result.real = c1.real + c2.real;  /* add real parts */
    result.imag = c1.imag + c2.imag;  /* add imaginary parts */
    printf("  real: %.2f + %.2f = %.2f\n", c1.real, c2.real, result.real);
    printf("  imag: %.2f + %.2f = %.2f\n", c1.imag, c2.imag, result.imag);
    return result;
}
void displayComplex(struct Complex c)
{
 printf("%.2f + %.2fi\n", c.real, c.imag);
}
