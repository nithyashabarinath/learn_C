/*REQUIREMENT:Replace every run of multiple consecutive spaces with a single space.
 DESIGN:
List of Variables: str,i(read position), j(write position),lastWasSpace(flag for last character being a space),
                 removed (counter for extra spaces) 
   1.i = READ position  - looks at every character of the original string
      j = WRITE position - where the next kept character is stored
   2.Because j never gets ahead of i, we can write the cleaned text back
      into the same array without overwriting characters we still need.
   3.For each character:
       - if it is a space AND the character we kept just before was also
         a space, skip it (do not copy it)
       - otherwise copy it to str[j] and move j forward
   4.A flag, lastWasSpace, remembers whether the last kept character was
    a space.
 TEST CASE:
 "i    love coding  in    c  "
 Cleaned string: "i love coding in c"

 */
#include <stdio.h>
#include <string.h>
#define MAX_LEN 200   
int main(void)
{
    char str[MAX_LEN];
    int i;                  
    int j = 0;              
    int lastWasSpace = 0;   
    int removed = 0;     
    printf("Enter a sentence: ");
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("\nOriginal string: \"%s\"\n\n", str);
    for (i = 0; str[i] != '\0'; i++)
     {
        if (str[i] == ' ' && lastWasSpace)
        {
        printf(" position %d: extra space removed\n", i);
        removed++;
        } else
        {
            str[j] = str[i];
            j++;
            lastWasSpace = (str[i] == ' ');
        }
    }
    str[j] = '\0';
    printf("\nCleaned string: \"%s\"\n", str);
    return 0;
}
