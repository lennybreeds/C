#include <stdio.h> 
#include <string.h>
int main() 
{
    char name[100];
    printf("Enter name:",name);
    scanf("%s",name);
    printf("The reverse of the string is %s\n",strrev(name));
}