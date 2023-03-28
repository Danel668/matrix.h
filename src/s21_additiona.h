#ifndef S21_ADDITIONAL_H
#define S21_ADDITIONAL_H

#include "s21_matrix.h"

int checkCor(matrix_t A);
void copyMatrix(matrix_t A, matrix_t *B);
void subMatrix(matrix_t A, int row, int column, matrix_t *B);

#endif  // S21_ADDITIONAL_H