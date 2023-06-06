#include <stdio.h>

// Derivative of function
double funcDash(double x, double y)
{
    return x + y;
}

double Euler(double x, double fx, double val, double h)
{
    double fx1 = fx, x1 = x, k1;
    while (x1 < val) {
        k1 = funcDash(x1, fx1);
        fx1 = fx1 + h * k1;
        x1 = x1 + h;
    }
    return fx1;
}

int main()
{
    double x, fx, h, val;

    printf("Enter Value of x : ");
    scanf("%lf", &x);
    printf("Enter Value of f(x) : ");
    scanf("%lf", &fx);
    printf("Enter x to be found: ");
    scanf("%lf", &val);
    printf("Enter Value of h : ");
    scanf("%lf", &h);

    printf("Result of f(%lf) : %.8lf\n", val, Euler(x, fx, val, h));
}