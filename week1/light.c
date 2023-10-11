#include <stdio.h>


int main () {
    long long unsigned int result;
    long long unsigned int days;
    long long unsigned int lightspeed = 300000000;
    printf("Number of days: ");
    scanf("%llu",&days);
    result = lightspeed*days*24*60*60;
    printf("Light will travel %llu m in %llu days",result,days);
    return 0;
}