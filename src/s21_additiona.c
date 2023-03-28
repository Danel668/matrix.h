#include "s21_additiona.h"

int checkCor(matrix_t A) {
  int flag = 1;
  if (A.columns > 0 && A.rows > 0 && A.matrix != NULL) flag = 0;

  return flag;
}

void copyMatrix(matrix_t A, matrix_t *B) {
  s21_create_matrix(A.rows, A.columns, B);

  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      B->matrix[i][j] = A.matrix[i][j];
    }
  }
}

void subMatrix(matrix_t A, int row, int column, matrix_t *B) {
  s21_create_matrix(A.rows - 1, A.columns - 1, B);

  int new_i = 0, new_j = 0;

  for (int i = 0; i < A.rows; i++) {
    if (i == row) continue;

    for (int j = 0; j < A.columns; j++) {
      if (j == column) continue;

      B->matrix[new_i][new_j] = A.matrix[i][j];
      new_j++;

      if (new_j == B->columns) {
        new_j = 0;
        new_i++;
      }
    }
  }
}