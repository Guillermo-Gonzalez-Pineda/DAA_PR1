#include "../include/RowWiseMultiplier.hpp"

// Implementacion del método multiply
Matrix RowWiseMultiplier::multiply(const Matrix& matrix_a, const Matrix& matrix_b) const {
  int rows_a = matrix_a.getRows();
  int cols_a = matrix_a.getCols();
  int cols_b = matrix_b.getCols();

  Matrix result(rows_a, cols_b, 0, false);

  for (int i = 0; i < rows_a; i++) {
    for (int j = 0; j < cols_b; j++) {
      int sum = 0;
      for (int k = 0; k < cols_a; k++) {
        sum += matrix_a.getValue(i, k) * matrix_b.getValue(k, j);
      }
      result.setValue(i, j, sum);
    }
  }
  return result;
}