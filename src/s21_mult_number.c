#include "s21_additiona.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag1 = checkCor(*A);
  int res = 1;

  if (flag1 == 0) {
    res = 0;
    s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
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