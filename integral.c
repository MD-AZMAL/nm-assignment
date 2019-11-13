#include<stdio.h>

int main() {
    
    int n,fn,fr;
    double left,right,h,fi;

    printf("Composite integral Program\n");
    printf("Presently it supports the following functions\n");
    printf("1. sin(x)\n");
    printf("2. ln(x)\n");
    printf("3. x^2\n");
    printf("Choose a function :");
    scanf("%d",&f);
    printf("Enter no of intervals : ");
    scanf("%d",&n);
    printf("Enter left limit : ");
    scanf("%f",&left);
    printf("Enter right limit : ");
    scanf("%f",&right);
    printf("Compostite formulas\n");
    printf("1. Trapezoidal\n");
    printf("2. Simpsons (only for even interval length) \n");
    printf("Choose a method : ");
    scanf("%d",fr);

    if(fr == 1) {

    }

    return 0;
}
