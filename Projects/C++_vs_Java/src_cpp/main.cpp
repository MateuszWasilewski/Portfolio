#include <iostream>
#include "matrix.h"
#include "exp.h"

int main() {
    try {
        int accuracy;
        std::cin >> accuracy;

        Matrix matrix(std::cin);

        std::cout << exp(matrix, accuracy)->toString() << std::endl;

    } catch (std::string e) {
        std::cout << e << std::endl; 
    }
}