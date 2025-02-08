#ifndef COLUMNWISEMULTIPLIER_H
#define COLUMNWISEMULTIPLIER_H

#include "IMatrixMultiplier.hpp"

class ColumnWiseMultiplier : public IMatrixMultiplier {
public:
    Matrix multiply(const Matrix& A, const Matrix& B) const override;
};

#endif // COLUMNWISEMULTIPLIER_H
