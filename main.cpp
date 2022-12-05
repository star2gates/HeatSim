#include <iostream>
#include <fstream>
#include "HeatSystem.h"

int main() {
    std::ofstream infofile;
    infofile.open("HeatSystemInfo.csv");
    int _m=10,_n=10;
    double _initialT=100.0, _dt=0.01, _tf=100.0;
    infofile << "#size_m, size_n,initialT,time_step,time_final,total_runs," << std::endl;

    Matrix mat(_m,_n);
    mat.set(0,3, _initialT);
    std::cout << "Hello, World!\nRunning simulation!" << std::endl;
    HeatSystem system1(std::make_unique<Matrix>(mat),_dt);
    system1.initialT = _initialT;
    system1.simulate(_tf);

    infofile << _m << "," << _n << "," << _initialT << "," << _dt << "," << _tf << "," << system1.total_runs << "," << std::endl;
    infofile.close();

    return 0;
}
