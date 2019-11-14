/*
    COMPOSITE INTEGRAL USING TRAPEZOIDAL AND SYMPSONS RULE
    ------------------------------------------------------
    Name : Md. Azmal
    Regno : 1741012060
    Branch : CSE 'F'
    Semester : 5th
*/

#include<stdio.h>
#include<math.h>

double eval_f(int f, double x) {

    switch(f) {
        case 1 : return sin(x);
        case 2 : return log(x);
        case 3 : return x*x;
        case 4 : return sqrt(x);
    }

}


double trap(int n, int f, double left, double right) {

    int i;

    double sum_0_n, sum_in = 0, in_res,f0,fn,h,x0;
    
    h = (right - left) / (double)n;
    x0 = left;

    f0 = eval_f(f,x0);
    fn = eval_f(f,x0 + n*h);
    sum_0_n = f0 + fn;
    
    printf("\nIntermediate calculations results\n");
    printf("h : %lf\tf0 : %lf\tfn : %lf \n",h,f0,fn);

    for(i = 1,x0 = x0 + h; i <= n - 1; i++, x0 += h) {
        in_res = eval_f(f,x0);
        printf("fi : %lf\txi : %lf\ti : %d \n",in_res,x0,i);
        sum_in += in_res;
    }
    printf("\n\n");
    return (h/2) * (sum_0_n + 2*sum_in);
}

double simp(int n, int f, double left, double right) {

    int i;

    double sum_0_n, ev_s = 0, od_s = 0,in_res,f0,fn,h,x0;

    h = (right - left) / (double)n;
    x0 = left;

    f0 = eval_f(f,x0);
    fn = eval_f(f,x0 + n*h);
    sum_0_n = f0 + fn;

    printf("\nIntermediate calculations results\n");
    printf("h : %lf\tf0 : %lf\tfn : %lf \n",h,f0,fn);


    for(i = 1,x0 = x0 + h ; i <= n-1 ; i++, x0 += h) {
        in_res = eval_f(f,x0);
        printf("fi : %lf\txi : %lf\ti : %d \n",in_res,x0,i);
        if(i%2 == 1)
            od_s += in_res;
        else
            ev_s += in_res;
    }

    printf("\n\n");
    return (h/3)*(sum_0_n + 4*od_s + 2*ev_s);
}

int main() {
    
    int n,f,fr,i;
    double left,right,h,res;

    printf("Composite integral Program\n");
    printf("Presently it supports the following functions\n");
    printf("1. sin(x)\n");
    printf("2. ln(x)\n");
    printf("3. x^2\n");
    printf("4. x^(1/2)\n");
    printf("Choose a function :");
    scanf("%d",&f);
    printf("Enter left limit : ");
    scanf("%lf",&left);
    printf("Enter right limit : ");
    scanf("%lf",&right);
    printf("Enter no of intervals : ");
    scanf("%d",&n);
    printf("Compostite formulas\n");
    printf("1. Trapezoidal\n");
    printf("2. Simpsons (only for even interval length) \n");
    printf("Choose a method : ");
    scanf("%d",&fr);


    switch(fr) {
        case 1 : res = trap(n,f,left,right);
                 break;
        case 2 : res = simp(n,f,left,right);
                 break;
    }

    printf("Composite Integral result : %lf\n",res);

    return 0;
}

