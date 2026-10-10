/*REQUIREMENT:Check whether a string is a pangram.
       A pangram uses every letter A to Z at least once, in any case.
 DESIGN:
List of Variables:
 seen(array), i(loop), idx(index for the letter), missing(count of missing letters)
   1.Keep a "tick list" one slot for each letter of the alphabet.
   2.Go through the string; for every letter, tick its slot (set it to 1)
   3.Digits, spaces and symbols are not letters, so they are ignored.
   4.Afterwards, if ALL 26 slots are ticked, the string is a pangram.
 
TESTCASE: "The quick brown fox jumps over the lazy dog"  ->  pangram
 */
#include <stdio.h>
#include <string.h>
#define MAX_LEN   200   
#define ALPHABET   26   
int main(void)
{
    char str[MAX_LEN];
    int seen[ALPHABET] = {0};   
    int i, idx;
    int missing = 0;           
    printf("Enter a sentence: ");
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("\nYou entered: \"%s\"\n\n", str);
   
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z') 
        {
            idx = str[i] - 'a';             
        } else if (str[i] >= 'A' && str[i] <= 'Z') 
        {
            idx = str[i] - 'A';              
        } else 
        {
            continue;                       
        }
        if (seen[idx] == 0)
        {
            printf(" new letter '%c' slot %d\n", 'a' + idx, idx);
        }
        seen[idx] = 1;                       
    }
   /* printf("\nMissing letters: ");
    for (i = 0; i < ALPHABET; i++) 
    {
        if (seen[i] == 0) 
        {
            printf("%c ", 'a' + i);    
            missing++;
        }
    }*/
    printf("\n");
    if (missing == 0)
    {
        printf("\nResult: the string is a pangram.\n");
    } else 
    {
        printf("\nResult: the string is NOT a pangram\n");
    }
    return 0;
}
