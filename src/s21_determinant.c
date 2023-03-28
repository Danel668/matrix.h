#include "s21_additiona.h"

int s21_determinant(matrix_t *A, double *result) {
  int flag1 = checkCor(*A);
  int res = 1;
  double det = 1.0;

  if (flag1 == 0) {
    res = 2;
    if (A->rows == A->columns) {
      res = 0;

      matrix_t B;
      copyMatrix(*A, &B);

      int i, j, k;

      for (i = 0; i < B.rows - 1; i++) {
        if (B.matrix[i][i] == 0) {
          for (k = i + 1; k < B.rows; k++) {
            if (B.matrix[k][i] != 0) {
              for (j = i; j < B.columns; j++) {
                double temp = B.matrix[i][j];
                B.matrix[i][j] = B.matrix[k][j];
                B.matrix[k][j] = temp;
              }
              det *= -1.0;
              break;
            }
          }
        }

        if (B.matrix[i][i] != 0) {
          for (k = i + 1; k < B.rows; k++) {
            double factor = B.matrix[k][i] / B.matrix[i][i];
            for (j = i; j < B.columns; j++) {
              B.matrix[k][j] -= factor * B.matrix[i][j];
            }
          }
        }
      }

      for (i = 0; i < B.rows; i++) {
        det *= B.matrix[i][i];
      }

      s21_remove_matrix(&B);

      *result = det;
    }
  }

  return res;
}