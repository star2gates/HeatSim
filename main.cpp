#include <iostream>
#include "HeatSystem.h"

int main() {
    Matrix mat(5,5);
    mat.set(2,2, 10);
    std::cout << "Hello, World!" << std::endl;
    HeatSystem system1(std::make_unique<Matrix>(mat),0.01);
    system1.simulate(10);
    return 0;
}
