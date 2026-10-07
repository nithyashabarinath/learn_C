#include <stdio.h>
#include <stdlib.h>
 int main()
{
    char str[10];
    int count=0;
    printf("enter a string:\n");
    fgets(str,sizeof(str),stdin);
    for(count=0;count<=10;count++)
     { 
        printf("%c\t",str[count]);
    
       }
     
    return 0;
}