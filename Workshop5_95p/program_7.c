/*
 * program 7
 * program_7.c
 * Nguyen Tri Phuc - HE176442
 * 20-06-2022
 */
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/* Caluclate root of linear equation */
void linear_root(double a, double b)
{
    if(a == 0 && b == 0)
        printf("Infinity root!");
    else if(a == 0 && b != 0)
        printf("No root!");
    else
    {
        double root = -b/a;
        if(root == 0)
            root *= -1;
        printf("Eqution have one root: %lf", root);
    }
}

/* Calculate roots of quadratic equation */
int roots(double a, double b, double c, double *r1, double *r2)
{
    if(a == 0)
        return 2;
    double delta = b*b - a*c*4;
    if(delta < 0)
        return -1;
    else if(delta == 0)
    {
        *r1 = -b / (a*2.0);
        return 0;
    }
    double sq = sqrt(delta); /// sqare root of delta
    *r1 = (-b + sq) / (a*2.0);
    *r2 = (-b - sq) / (a*2.0);
    return 1;
}

int main()
{
    /* Input */
    printf("Enter 3 parameters a, b, c respectively: ");
    double *a = (double*)malloc(sizeof(double));
    double *b = (double*)malloc(sizeof(double));
    double *c = (double*)malloc(sizeof(double));
    scanf("%lf%lf%lf", a, b, c);
    /* End of Input */

    /* Implement */
    double *r1 = (double*)malloc(sizeof(double));
    double *r2 = (double*)malloc(sizeof(double));
    int flag = roots(*a, *b, *c, r1, r2);
    /* End of Implement */

    /* Output */
    if(flag == -1)
        printf("No root!");
    else if(flag == 0)
        printf("Equation have one root: %lf", *r1);
    else if(flag == 1)
        printf("Equation have two roots: r1 = %lf; r2 = %lf", *r1, *r2);
    else
    	linear_root(*b, *c);
    free(a);
    free(b);
    free(c);
    free(r1);
    free(r2);
    /* End of Output */

    return 0;
}



