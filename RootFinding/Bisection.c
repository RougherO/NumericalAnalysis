#include <math.h>
#include <stdio.h>

// Function whose root is to be found
double func(double x)
{
    return tan(x) - x;
}

double Bisection(double start, double end, double tol /* tolerance value or allowed error */)
{
    double mid = (start + end) / 2;
    // fabs(func(mid)) checks whether |func(mid) - 0| < error permissible ,i.e., whether f(mid) is near to zero or not
    while (fabs(func(mid)) >= tol) {
        if (func(mid) * func(start) < 0) {
            // this condition means that end and mid are on same side of root
            // so end is shifted to mid to bring it closer to root
            end = mid;
        } else {
            // this condition means that start and mid are on same side of root
            // so end is shifted to mid to bring it closer to root
            start = mid;
        }
        // recalculating mid and checking again
        mid = (start + end) / 2;
    }
    return mid;
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

    printf("Root : %.7lf\n", Bisection(start, end, tol));
}