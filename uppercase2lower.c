/*REQUIREMENT:Convert all uppercase letters in a string to lowercase.
      Lowercase letters and non-letters are left exactly as they are.
 DESIGN:
List of Variables: str (input string), i (loop variable), changed (counter for converted letters)
  1. Read a string from the user.
  2. Iterate through each character of the string.
  3. If an uppercase letter is found, convert it to lowercase.
  4. Print the modified string and the number of converted letters.
TEST CASES:
- Input: "Hello World!" -> Output: "hello world!"
- Input: "C PROGRAMMING" -> Output: "c programming"
- Input: "123 ABC def" -> Output: "123 abc def"*/

#include <stdio.h>
#include <string.h>
#define MAX_LEN 100   

int main(void)
{
    char str[MAX_LEN];
    int i;
    int changed = 0; 
    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("\nOriginal string: \"%s\"\n\n", str);
    for (i = 0; str[i] != '\0'; i++) 
    {

        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            printf("  position %d: '%c' (ASCII %d) -> '%c' (ASCII %d)\n",
                   i, str[i], str[i], str[i] + 32, str[i] + 32);
            str[i] = str[i] + 32;      
            changed++;
        }
       
    }
    printf("\nConverted string: \"%s\"\n", str);
    printf("%d letter(s) converted out of %d characters.\n", changed, i);
    return 0;
}

