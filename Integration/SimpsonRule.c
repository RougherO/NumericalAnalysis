#include <stdio.h>

double func(double x)
{
    return x * x;
}

double SimpInt(double llimit, double ulimit, unsigned int division)
{
    // (b - a) / N
    double interval = (ulimit - llimit) / division;

    // Storing f(x0) + f(xn) first
    double val = func(llimit) + func(ulimit);

    // Iterating while i < N - 1 as we add
    // 4 * f(lower + (N - 1) * (b - a) / N) at the end
    for (int i = 1; i + 1 < division; i += 2) {
        val += 4 * func(llimit + i * interval) + 2 * func(llimit + (i + 1) * interval);
    }
    val += 4 * func(ulimit - interval); // 4 * func(llimit + (N - 1) * interval)

    // Mulitplying by 1/3 * (b - a) / N
    val *= interval / 3;

    return val;
}

int main()
{
    double llimit, ulimit;
    unsigned int division;

    printf("Enter lower limit : ");
    scanf("%lf", &llimit);
    printf("Enter upper limit : ");
    scanf("%lf", &ulimit);
    printf("Enter number of divisions : ");
    scanf("%u", &division);

    // In Simpson's 1/3rd rule divisions should be even
    // So we keep checking till user has put in an even
    // Number of divisions.
    while (division % 2) {
        printf("Enter Even divisions : ");
        scanf("%u", &division);
    }

    printf("Result : %lf", SimpInt(llimit, ulimit, division));
}