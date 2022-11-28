//
// Fixed by Anand Saggu on 11/27/2022.
//

//
// Created by Inderpal Singh on 11/12/22.
//


#include "Matrix.h"
#include <vector>

Matrix::Matrix(int m, int n) {
    i = n;
    j = m;
    matrix = std::vector(i, std::vector<double>(j, 0));
}

auto Matrix::get(int m, int n) -> double {
    return matrix.at(m).at(n);
}

auto Matrix::set(int m, int n, double data) -> void {
    matrix.at(m).at(n) = data;
}
