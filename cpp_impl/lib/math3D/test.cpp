#include "math3D.hpp"
#include <iostream>

#include <random>

int main () {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> dist(0, 100000);
    mat3D A;
    for (int i = 0; i < 3 ; i++) {
        for (int j = 0; j < 3; j++) {
            A[i][j] = dist(rng);
        }
    }
    A.print();
    std::cout << A.det() << std::endl;
    A.inv().print();
    (A * A.inv()).print();
}
