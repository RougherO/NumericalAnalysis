#include <stdio.h>

void GJ(unsigned size, double (*matrix)[size + 1])
{
    for (int row = 0; row < size; ++row) {
        for (int row_ind = 0; row_ind < size; ++row_ind) {
            if (row_ind != row) {
                double coeff1 = matrix[row][row];
                double coeff2 = matrix[row_ind][row];
                for (int col_ind = 0; col_ind < size + 1; ++col_ind) {
                    matrix[row_ind][col_ind] = coeff1 * matrix[row_ind][col_ind] - coeff2 * matrix[row][col_ind];
                }
            }
        }
    }
    return;
}

int main()
{
    unsigned size = 0;

    printf("Enter Number of Variables : ");
    scanf("%u", &size);

    double matrix[size][size + 1];

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("Enter Equation [%d] Coefficient [%d] : ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
        printf("Enter Constant Value of Equation [%d] : ", i + 1);
        scanf("%lf", &matrix[i][size]);
    }

    GJ(size, matrix);

    for (int i = 0; i < size; ++i) {
        printf("Variable [%d] : %lf\n", i + 1, matrix[i][size] / matrix[i][i]);
    }
}