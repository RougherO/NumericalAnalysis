#include <stdio.h>

double LI(unsigned int sizeOfDataPoints, double (*dataPoints)[sizeOfDataPoints], double x)
{
    double fx = 0, numerator, denominator;
    for (int i = 0; i < sizeOfDataPoints; ++i) {
        numerator = denominator = 1;
        for (int j = 0; j < sizeOfDataPoints; ++j) {
            if (j != i) {
                numerator *= (x - dataPoints[0][j]);
                denominator *= (dataPoints[0][i] - dataPoints[0][j]);
            }
        }
        fx += numerator / denominator * dataPoints[1][i];
    }
    return fx;
}

int main()
{
    // Taking size of dataset
    unsigned size = 0;
    printf("Enter number of data points : ");
    scanf("%u", &size);

    // Store value of x in first row and f(x) in second row
    double arr[2][size];

    // It is being assumed that data points are being added
    // in sorted order
    for (int i = 0; i < size; ++i) {
        printf("Enter element %d [x, f(x)] : ", i + 1);
        scanf("%lf %lf", arr[0] + i, arr[1] + i);
    }

    // Taking input of x whose value is to be found
    double x = 0;
    printf("Enter x for f(x) : ");
    scanf("%lf", &x);

    printf("Calculated value of f(%lf) : %lf\n", x, LI(size, arr, x));
}