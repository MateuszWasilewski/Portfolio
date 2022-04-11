#include <iostream>
#include <string.h>
#include "matrix.h"
#include "memory"

using std::unique_ptr;
using std::make_unique;

Matrix::Matrix(int height, int width) {
    initialize(height, width);
}

Matrix::~Matrix() {
    if (data != NULL) {
        for (int iter = 0; iter < height; iter++) {
            delete [] data[iter];
        }
        delete [] data;
    }
}

void Matrix::initialize(int height, int width) {
    if (width <= 0) throw "Width cannot be non positive";
    if (height <= 0) throw "Height cannot be non positive";

    this->width = width;
    this->height = height;
    data = new double*[height];
    for (int iter = 0; iter < height; iter++) {
        data[iter] = new double[width]();
    }
}

std::unique_ptr<Matrix> Matrix::identity(void) const {
    if (width != height) throw "Matrix needs to be square";

    unique_ptr<Matrix> result = make_unique<Matrix>(height, width);

    for (int iter = 0; iter < result->width; iter++) {
        result->data[iter][iter] = 1;
    }
    return result;
}

Matrix::Matrix(std::istream& input) {
    int height, width;
    input >> height >> width;
    initialize(height, width);
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            input >> this->data[row][column];
        }
    }
}

Matrix::Matrix(const Matrix& that) {
    initialize(that.height, that.width);
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            this->data[row][column] = that.data[row][column];
        }
    }
}

std::string Matrix::toString() {
    std::string result;
    for (int row = 0; row < height; row++) {
        result += "( ";
        for (int column = 0; column < width; column++) {
            result += std::to_string(data[row][column]) + " ";
        }
        result += ")\n";
    }
    return result;
}

unique_ptr <Matrix> Matrix::operator* (const Matrix& that) const {
    if (this->width != that.height) 
        throw "Matrixes cannot be multiplied together, dimensions don't match";

    unique_ptr <Matrix> result = make_unique<Matrix>(this->height, that.width);

    for (int row = 0; row < result->height; row++) {
        for (int column = 0; column < result->width; column++) {
            for (int iter = 0; iter < this->width; iter++) {
                result->data[row][column] += this->data[row][iter] * that.data[iter][column];
            }
        }
    }
    return result;
}

void Matrix::operator*= (const Matrix& that) {
    unique_ptr <Matrix> result = *this * that;

    // Swaping arrays, 2d array in result will be destroyed.
    double** swap = this->data;
    this->data = result->data;
    result->data = swap;

    this->height = result->height;
    this->width = result->width;
}

unique_ptr<Matrix> Matrix::operator* (double value) const {
    unique_ptr<Matrix> result = make_unique<Matrix>(*this);
    for (int row = 0; row < result->height; row++) {
        for (int column = 0; column < result->width; column++) {
            result->data[row][column] *= value;
        }
    }
    return result;
}

void Matrix::operator*= (double value) {
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            data[row][column] *= value;
        } 
    }
}

void Matrix::operator+= (const Matrix& that) {
    if (this->width != that.width) throw "Width doesn't match during matrix addition";
    if (this->height != that.height) throw "Height doesn't match during matrix addition";

    for (int row = 0; row < this->height; row++) {
        for (int column = 0; column < this->width; column++) {
            this->data[row][column] += that.data[row][column];
        }
    }
}

unique_ptr<Matrix> Matrix::operator+ (const Matrix& that) const {
    unique_ptr<Matrix> result = make_unique<Matrix>(*this);
    *result += that;
    return result;
}