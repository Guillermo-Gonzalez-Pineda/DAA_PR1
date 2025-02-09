#include "../include/RowWiseMultiplier.hpp"

// Implementacion del método multiply
Matrix RowWiseMultiplier::multiply(const Matrix& matrix_a, const Matrix& matrix_b) const {
  int num_filas_a = matrix_a.getRows();
  int num_columnas_a = matrix_a.getCols(); // Igual al numero de columnas de B
  int num_columnas_b = matrix_b.getCols();

  Matrix result(num_filas_a, num_columnas_b);
  for (int i = 0; i < num_filas_a; i++) {
    for (int j = 0; j < num_columnas_b; j++) {
      int suma = 0;
      for (int k = 0; k < num_columnas_a; k++) {
        suma += matrix_a.getValue(i, k) * matrix_b.getValue(k, j);
      }
      result.setValue(i, j, suma);
    }
  }
  return result;
}