#ifndef EXP_H
#define EXP_H

#include "matrix.h"

// Calculates function exp(matrix) using series expantion.
// Calculations are performed up to a given index.
std::unique_ptr<Matrix> exp(const Matrix& matrix, int accuracy);

#endif /* EXP_H */