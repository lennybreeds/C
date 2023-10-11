#include <stdio.h>

long long int factorial (long long int num){
    long long int total = 1;
    for (int l = 1; l<=num;l++){
        total = total*l;
    }
    return total;
}

int main(){
    long long int num;
    for (int i = 0; i<30;i++) {
    num = factorial(i);
    printf("The factorial of %d is %llu\n",i,num);
    };

    return 0;
}