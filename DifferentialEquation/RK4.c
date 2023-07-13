#include <stdio.h>

// Derivative of function
double funcDash(double x, double y)
{
    return x + y;
}

double RK4(double x, double fx, double val, double h)
{
    double fx1 = fx, x1 = x, k1, k2, k3, k4;
    while (x1 < val) {
        k1 = funcDash(x1, fx1);
        k2 = funcDash(x1 + (h / 2), fx1 + (h / 2) * k1);
        k3 = funcDash(x1 + (h / 2), fx1 + (h / 2) * k2);
        k4 = funcDash(x1 + h, fx1 + h * k3);
        fx1 = fx1 + (h / 6) * (k1 + 2 * (k2 + k3) + k4);
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

    printf("Result of f(%lf) : %.8lf\n", val, RK4(x, fx, val, h));
}