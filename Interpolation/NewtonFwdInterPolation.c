#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double* generateTable(double* arr, int size)
{
    double* table = malloc(size * size * sizeof(double));

    // Filling up first row
    for (int i = 0; i < size; ++i) {
        table[0 * size + i] = arr[i];
    }

    // Creating the rest of the table
    for (int i = 1; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            table[i * size + j] = table[(i - 1) * size + j] - table[(i - 1) * size + (j - 1)];
        }
    }

    return table;
}

double NFI(unsigned int sizeofDataPoints, double (*dataPoints)[sizeofDataPoints], double x)
{
    // Generate the intrapolation table
    double* table = generateTable(dataPoints[1], sizeofDataPoints);

    // f_x is the resultant value
    // p is the p in formula Sorry can't explain this :P
    double fx = dataPoints[1][0], factorial = 1;
    double p = (x - dataPoints[0][0]) / (dataPoints[0][1] - dataPoints[0][0]);

    for (int i = 1; i < sizeofDataPoints; ++i) {
        fx += p / factorial * table[i * sizeofDataPoints + i];
        factorial *= i;
        p *= p - i;
    }

    free(table);

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

    printf("Calculated value of f(%lf) : %lf\n", x, NFI(size, arr, x));
}