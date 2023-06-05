#include <math.h>
#include <stdio.h>

// Function whose root is to be found
double func(double x)
{
    return tan(x) - x;
}

// Derivative of function whose root is to be found
double funcDash(double x)
{
    return 1 / pow(cos(x), 2) - 1;
}

double NewtonRaphson(double start, double tol)
{
    // Next value of root
    double next = start - func(start) / funcDash(start);
    while (fabs(func(next)) >= tol) {
        start = next;
        next = start - func(start) / funcDash(start);
    }
    return next;
}

int main()
{
    double start = 0, tol = 0;

    printf("Enter starting value : ");
    scanf("%lf", &start);

    printf("Enter tolerance value : ");
    scanf("%lf", &tol);

    printf("Root : %lf\n", NewtonRaphson(start, tol));
}