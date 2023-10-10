#include <stdio.h>

int factorial (int num){
    if (num > 0){
        return factorial(num-1)*num;
    }
}

int main(){
    int num;
    scanf("%d",&num);
    num = factorial(num);
    printf("%d",num);
}