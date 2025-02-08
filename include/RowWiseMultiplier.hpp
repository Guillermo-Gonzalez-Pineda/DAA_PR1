#ifndef ROWWISEMULTIPLIER_H
#define ROWWISEMULTIPLIER_H

#include "IMatrixMultiplier.hpp"

class RowWiseMultiplier : public IMatrixMultiplier {
  public:
    Matrix multiply(const Matrix& matrix_a, const Matrix& matrix_b) const override;
};

#endif