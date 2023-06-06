#include <stdio.h>

// Derivative of function
double funcDash(double x, double y)
{
    return x + y;
}

double RK2(double x, double fx, double val, double h)
{
    double fx1 = fx, x1 = x, k1, k2;
    while (x1 < val) {
        k1 = funcDash(x1, fx1);
        k2 = funcDash(x1 + (h / 2), fx1 + (h / 2) * k1);
        fx1 = fx1 + h * k2;
        x1 = x1 + h;
    }
    return fx1;
}

int main()
{
    double x0, fx0, h, val;

    printf("Enter Value of x : ");
    scanf("%lf", &x0);
    printf("Enter Value of f(x) : ");
    scanf("%lf", &fx0);
    printf("Enter x to be found: ");
    scanf("%lf", &val);
    printf("Enter Value of h : ");
    scanf("%lf", &h);

    printf("Result of f(%lf) : %.8lf\n", val, RK2(x0, fx0, val, h));
}