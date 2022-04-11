#include "memory"
#include "exp.h"

using std::unique_ptr;
using std::make_unique;

unique_ptr<Matrix> exp(const Matrix& matrix, int accuracy) {
    unique_ptr<Matrix> factor = matrix.identity();
    unique_ptr<Matrix> result = make_unique<Matrix>(*factor);

    for (double iter = 1; iter <= accuracy; iter++) {
        *factor *= matrix;
        *factor *= (1 / iter);
        *result += *factor;
    }
    return result;
}