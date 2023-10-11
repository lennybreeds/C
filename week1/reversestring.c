#include <stdio.h>
#include <string.h>

int main (){
    char word[15];
    printf("String: ");
    scanf("%s",word);
    int size = strlen(word);
    printf("%d",size);
    char result[size];
    for (int i=0;i<size;i++){
        result[i] = word[size-i];
    }
    printf("%s",result);
    return 0;
}