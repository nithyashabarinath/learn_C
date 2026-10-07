/*bitwise operations
REQUIREMENT : You are given an 8-bit register represented as an unsigned char. 
              Write a function to: ● Set the 3rd bit (bit index 2). 
                     ● Clear the 6th bit (bit index 5). 
                     ● Toggle the 1st bit (bit index 0). Return the modified register value.  
                     Note: Use bitwise operators only. 
                     Avoid loops or conditionals. 
DESIGN:    
        List of variables: reg_8 (input register), 
                          setbit_3, clearbit_6, togglebit_1(modified register values)
        1. Read the input register value into reg_8.
        2. Set the 3rd bit of reg_8 using bitwise OR operation and store the result in setbit_3. 
        3. Clear the 6th bit of reg_8 using bitwise AND operation with negation and store the result in clearbit_6.
        4. Toggle the 1st bit of reg_8 using bitwise XOR operation and store the result in togglebit_1.
        5. Print the modified register values setbit_3, clearbit_6, and togglebit_1.                
                 */

#include<stdio.h>
int main()
{
    unsigned char reg_8;
    scanf("%d",&reg_8);
    unsigned char setbit_3 = reg_8 |(1<<2);
    unsigned char clearbit_6=reg_8 &~(1<<5);
    unsigned char togglebit_1 = reg_8 ^(1);
    printf("\nthe 3rd bit is set and modified value is %d",setbit_3);
    printf("\nthe 6th bit is cleared and modified value is %d",clearbit_6);
    printf("\nthe 1st bit is toggled and modified value is %d",togglebit_1);
}
