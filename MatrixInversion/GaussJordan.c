#include <stdio.h>

void GJ(unsigned size, double (*matrix)[2 * size])
{
    for (int row = 0; row < size; ++row) {
        for (int row_ind = 0; row_ind < size; ++row_ind) {
            if (row_ind != row) {
                double coeff1 = matrix[row][row];
                double coeff2 = matrix[row_ind][row];
                for (int col_ind = 0; col_ind < 2 * size; ++col_ind) {
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

    printf("Enter size of Matrix : ");
    scanf("%u", &size);

    double matrix[size][2 * size];

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("Enter Term[%d][%d] : ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
        for (int j = size; j < 2 * size; ++j) {
            matrix[i][j] = j - size == i ? 1 : 0;
        }
    }

    GJ(size, matrix);

    for (int i = 0; i < size; ++i) {
        for (int j = size; j < 2 * size; ++j) {
            matrix[i][j] /= matrix[i][i];
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}