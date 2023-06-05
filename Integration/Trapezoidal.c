#include <stdio.h>

double func(double x)
{
    return x * x;
}

double TrapInt(double llimit, double ulimit, unsigned int division)
{
    // (b - a) / N
    double interval = (ulimit - llimit) / division;

    // Storing f(x0) + f(xn) first
    double val = func(llimit) + func(ulimit);

    // Iterating while i < N
    // And adding 2 * f(xi) every step
    for (int i = 1; i < division; ++i) {
        val += 2 * func(llimit + i * interval);
    }

    // Mulitplying by 1/2 * (b - a) / N
    val *= interval / 2;

    return val;
}

int main()
{
    double llimit, ulimit, division;

    printf("Enter lower limit : ");
    scanf("%lf", &llimit);
    printf("Enter upper limit : ");
    scanf("%lf", &ulimit);
    printf("Enter number of divisions : ");
    scanf("%lf", &division);

    printf("Result : %lf", TrapInt(llimit, ulimit, division));
}