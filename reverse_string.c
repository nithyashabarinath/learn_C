#include <stdio.h>
#include <string.h>
 int main()
{
    char str[100];
    int count=0;
    printf("enter a string:\n");
    fgets(str,sizeof(str),stdin);
    int size_str = strlen(str);
     printf("the length of the string is %d\n",size_str);
     printf("the reversed string is :\n");
    for(count=size_str-1;count>=0;count--)
     {
        printf("%c",str[count]);
    
       }
    
    return 0;
}