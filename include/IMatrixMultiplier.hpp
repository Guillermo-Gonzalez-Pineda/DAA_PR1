#ifndef IMATRIXMULTIPLIER_H
#define IMATRIXMULTIPLIER_H

#include "Matrix.hpp"

class IMatrixMultiplier {
  public:
    virtual ~IMatrixMultiplier() = default;

    // Metodo virtual para multiplicar matrices
    virtual Matrix multiply(const Matrix& matrix_a, const Matrix& matrix_b) const = 0;
};

#endif