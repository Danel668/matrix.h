#include "s21_additiona.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag1 = checkCor(*A);
  int flag2 = checkCor(*B);
  int res = 1;
  if (flag1 + flag2 == 0) {
    res = 2;
    if (A->rows == B->rows && A->columns == B->columns) {
      res = 0;
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
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