#include <stdio.h>

int main()
{
    // counter variables i,j,k and number of unkowns n
    int i, j, k, n;
    // 2D matrix a to store coeffecients
    // 1D array x to store solutions
    float a[10][10], x[10];

    printf("Enter number of unkowns: ");
    scanf("%d", &n); // Taking input number of unkowns from user

    for (i = 0; i < n; i++) {
        printf("Enter coefficients of equation %d: ", i + 1);
        for (int j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]); // Taking input for Augmented Matrix
        }
    }

    // Using nested loop to create Upper Triangular Matrix
    for (j = 0; j < n; j++) {
        for (i = j + 1; i < n; i++) {
            c = a[i][j] / a[j][j];
            for (k = 0; k <= n; k++)
                a[i][k] = a[i][k] - c * a[j][k];
        }
    }

    // Calculating Solutions
    printf("Solution: ");
    for (i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++)
            x[i] -= a[i][j] * x[j];
        x[i] /= a[i][i];
        printf("%.4f, ", x[i]);
    }

    printf("\n");
    return 0;
}
