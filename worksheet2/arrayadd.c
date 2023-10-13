#include <stdio.h>

int main () {
    int nums[5];
    int total = 0;
    int num = 0;
    for (int i=0;i<5;i++){
        scanf("%d",&num);
        nums[i] = num;
    }
    for (int i=0;i<5;i++){
        total = total + nums[i];
    }
    printf("%d",total);
    return 0;
}