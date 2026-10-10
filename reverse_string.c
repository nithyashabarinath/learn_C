/*REQUIREMENT:Reverse a string using an iterative approach (a loop).
  DESIGN:(swap from both ends, moving towards the middle)
 1.i starts at the first character, j starts at the last character.
 2.Swap str[i] and str[j], then move inwards (i++, j--).
 3.Stop when i reaches or passes j; the whole string is then reversed.
 4.We only need to go halfway, because each swap fixes TWO characters.

 TEST CASES:
 1. Input: "Hello, World!", Output: "!dlroW ,olleH
 */
#include <stdio.h>
#include <string.h>
#define MAX_LEN 100 
int main(void)
{
    char str[MAX_LEN];
    int i, j, len;
    char temp;                          
    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = '\0';
    len = (int)strlen(str);           
    printf("\nOriginal string: \"%s\" (%d characters)\n\n", str, len);
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        printf(" swap str[%d]='%c' and str[%d]='%c'\n",
               i, str[i], j, str[j]);
        temp   = str[i];                
        str[i] = str[j];                
        str[j] = temp;                   
    }
    printf("\nReversed string: \"%s\"\n", str);
    return 0;
}
