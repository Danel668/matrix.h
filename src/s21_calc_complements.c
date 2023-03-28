#include "s21_additiona.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag1 = checkCor(*A);
  int res = 1;

  if (flag1 == 0) {
    res = 2;

    if (A->rows == A->columns && A->rows > 1) {
      res = 0;

      s21_create_matrix(A->rows, A->columns, result);

      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          double det;
          matrix_t sub;
          subMatrix(*A, i, j, &sub);
          s21_determinant(&sub, &det);
          s21_remove_matrix(&sub);
          double complement = pow(-1, i + j) * det;
          result->matrix[i][j] = complement;
        }
      }
    }
  }

  if (res != 0) {
    result->matrix = NULL;
    result->rows = 0;
    result->columns = 0;
  }

  return res;
}