#include "s21_additiona.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag1 = checkCor(*A);
  int flag2 = checkCor(*B);
  int flag = 0;
  if (flag1 + flag2 == 0) {
    if (A->columns == B->columns && A->rows == B->rows) {
      flag = 1;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) flag = 0;
        }
      }
    }
  }
  return flag;
}