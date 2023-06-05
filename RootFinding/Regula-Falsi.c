#include <math.h>
#include <stdio.h>

// Function whose root is to be found
double func(double x)
{
    return tan(x) - x;
}

double RegulaFalsi(double start, double end, double tol /* tolerance value or allowed error */)
{
    double t_root = (start * func(end) - end * func(start)) / (func(end) - func(start));
    // fabs(func(t_root)) checks whether |func(t_root) - 0| < error permissible ,i.e., whether f(mid)
    // is nearer to zero with an error less than tolerance
    while (fabs(func(t_root)) >= tol) {
        if (func(t_root) * func(start) < 0) {
            // this condition means that end and t_root are on same side of root
            // so end is shifted to t_root to bring it closer to root
            end = t_root;
        } else {
            // this condition means that start and t_root are on same side of root
            // so end is shifted to t_root to bring it closer to root
            start = t_root;
        }
        // recalculating t_root and checking again
        t_root = (start * func(end) - end * func(start)) / (func(end) - func(start));
    }
    return t_root;
}

int main()
{
    double start = 0, end = 0, tol = 0;

    printf("Enter starting value : ");
    scanf("%lf", &start);

    printf("Enter ending value : ");
    scanf("%lf", &end);

    printf("Enter tolerance value : ");
    scanf("%lf", &tol);

    printf("Root : %.7lf\n", RegulaFalsi(start, end, tol));
}