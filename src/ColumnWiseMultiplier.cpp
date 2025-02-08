#include "../include/ColumnWiseMultiplier.hpp"

// Implementación del método multiply
Matrix ColumnWiseMultiplier::multiply(const Matrix& A, const Matrix& B) const {
    int rowsA = A.getRows();
    int colsA = A.getCols();
    int colsB = B.getCols();
    
    Matrix result(rowsA, colsB, false); // Matriz resultante

    for (int j = 0; j < colsB; ++j) {
      for (int i = 0; i < rowsA; ++i) {
        int sum = 0;
        for (int k = 0; k < colsA; ++k) {
            sum += A.getValue(i, k) * B.getValue(k, j); // Multiplicación y suma
        }
        result.setValue(i, j, sum);
      }
    }

    return result;
}
