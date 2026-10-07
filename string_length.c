#include <stdio.h>
#include <stdlib.h>
 int main()
{
    char str[100];
    int count=0;
    printf("enter a string:\n");
    fgets(str,sizeof(str),stdin);
    printf("%s \n", str);
    while(str[count]!='\0')
       { 
        count++;
       }
     printf("the length of the string is %d",count);
    return 0;
}