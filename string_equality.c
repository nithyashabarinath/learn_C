# include<stdio.h>
#include<string.h>
int main()
{
    char str1[20],str2[20];
    printf("Enter a string to compare:");
    fgets(str1,sizeof(str1),stdin);
    printf("\nEnter second string :");
    fgets(str2,sizeof(str2),stdin);
    if(strlen(str1)==strlen(str2))
    {
        for(int i=0;str1[i]!='\0';i++)
        {
           if(str1[i]==str2[i])
             {
                continue;   
             }
            else goto not_equal;
        }
        printf("the strings are equal");
    }
     else
    {
        not_equal:
        printf("\nthe strings are not equal");
    }
}