#include "s21_additiona.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag1 = checkCor(*A);
  int res = 1;

  if (flag1 == 0) {
    res = 2;
    if (A->columns == A->rows) {
      double det;
      s21_determinant(A, &det);

      if (det != 0) {
        res = 0;

        s21_create_matrix(A->rows, A->columns, result);

        matrix_t dop;
        s21_calc_complements(A, &dop);

        matrix_t trandop;

        s21_transpose(&dop, &trandop);
        s21_remove_matrix(&dop);

        double invdet = 1.0 / det;

        s21_mult_number(&trandop, invdet, result);

        s21_remove_matrix(&trandop);
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