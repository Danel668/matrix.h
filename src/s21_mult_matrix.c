#include "s21_additiona.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag1 = checkCor(*A);
  int flag2 = checkCor(*B);
  int res = 1;

  if (flag1 + flag2 == 0) {
    res = 2;
    if (A->columns == B->rows) {
      res = 0;

      s21_create_matrix(A->rows, B->columns, result);

      int i, j, k;
      for (i = 0; i < A->rows; i++) {
        for (j = 0; j < B->columns; j++) {
          double summ = 0.0;
          for (k = 0; k < A->columns; k++) {
            summ += A->matrix[i][k] * B->matrix[k][j];
          }
          result->matrix[i][j] = summ;
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