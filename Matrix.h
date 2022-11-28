//
// Fixed by Anand Saggu on 11/27/2022.
//

#ifndef HEATSIM_MATRIX_H
#define HEATSIM_MATRIX_H

//
// Created by Inderpal Singh on 11/12/22.
//

#pragma once
#include <vector>

class Matrix {
public:
    Matrix(int m, int n);
    [[nodiscard]] auto get(int m, int n) -> double;
    auto set(int m, int n, double data) -> void;
    [[nodiscard]] auto get_width() const -> int{ return j; };
    [[nodiscard]] auto get_height() const -> int{ return i; };
private:
    int i;
    int j;
    std::vector<std::vector<double>> matrix;

};


#endif //HEATSIM_MATRIX_H
