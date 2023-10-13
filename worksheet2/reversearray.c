#include <stdio.h>

int main (){
    int length;
    scanf("%d",&length);
    int array[length];
    for (int i=0;i<length;i++){
        int num;
        scanf("%d",&num);
        array[i] = num;
    }
    int a=0;
    int b=length-1;
    while (a < b){
        int temp = array[a];
        array[a] = array[b];
        array[b] = temp;
        a++;
        b--;
    }
        for (int i=0;i<length;i++){
        printf("%d\n",array[i]);
    }
    return 0;
}