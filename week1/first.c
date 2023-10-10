#include <stdio.h> 
int main() 
{
    float side1;
    float side2;
    printf("Enter side length one: ");
    scanf("%f",&side1);
    printf("Enter side length two: ");
    scanf("%f",&side2);
    printf("The area of the rectangle is %f\n.",side1*side2);
    return 0; 
}