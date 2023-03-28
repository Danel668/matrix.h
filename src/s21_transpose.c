#include "s21_additiona.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag1 = checkCor(*A);
  int res = 1;

  if (flag1 == 0) {
    res = 0;

    s21_create_matrix(A->columns, A->rows, result);

    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
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