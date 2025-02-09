#include "../include/ColumnWiseMultiplier.hpp"

// Implementación del método multiply
Matrix ColumnWiseMultiplier::multiply(const Matrix& matrix_a, const Matrix& matrix_b) const {
  int num_filas_a = matrix_a.getRows();
  int num_columnas_a = matrix_a.getCols(); // Igual al numero de columnas de B
  int num_columnas_b = matrix_b.getCols();

  Matrix result(num_filas_a, num_columnas_b);
  for (int i = 0; i < num_columnas_b; i++) {
    for (int j = 0; j < num_filas_a; j++) {
      int suma = 0;
      for (int k = 0; k < num_columnas_a; k++) {
        suma += matrix_a.getValue(j, k) * matrix_b.getValue(k, i);
      }
      result.setValue(j, i, suma);
    }
  }
  return result;
}
