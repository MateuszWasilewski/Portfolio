#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <memory>

class Matrix {
private:
    int width;
    int height;
    double** data;

    // Default initialization method, used because C++ doesn't support
    // calling contructor from constructor.
    void initialize(int height, int width);

public:
    // Default constructor which allow positive width and height of new matrix.
    // Otherwise, exception is thrown.
    Matrix(int height, int width);

    // Read information about new matrix from given scanner.
    Matrix(std::istream& input);

    // Copy constructor which creates new matrix, which is independent of the old one.
    Matrix(const Matrix& that);

    // Default destructor, deletes allocated dynamic memory.
    ~Matrix();

    // Method used to return whole Matrix as a string.
    std::string toString(void);

    // Returns identity matrix with size equal to given matrix.
    std::unique_ptr<Matrix> identity(void) const;

    // Matrix multiplication using n^3 algorithm.
    std::unique_ptr<Matrix> operator* (const Matrix& that) const;

    // Matrix multiplication, which sets result to first multiplied matrix.
    void operator*= (const Matrix& that);

    // Multiply matrix by constant value, return result.
    std::unique_ptr<Matrix> operator* (double value) const;

    // Multiply matrix by constant, set result to matrix.
    void operator*= (double value);

    // Add two matrixes, sets result to first.
    void operator+= (const Matrix& that);

    // Add two matrixes, returns result.
    std::unique_ptr<Matrix> operator+ (const Matrix& that) const;
};

#endif /* MATRIX_H */