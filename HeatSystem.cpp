//
// Fixed by Anand Saggu on 11/27/2022.
//

//
// Created by Inderpal Singh on 11/12/22.
//

#include "HeatSystem.h"
#include <utility>
#include <fstream>
#include <memory>
#include <iostream>

HeatSystem::HeatSystem(std::unique_ptr<Matrix> system, double dt) : system( std::move(system)), dt(dt) {

}

auto HeatSystem::simulate(double tf) -> void {
    time_elapsed = 0.0f;
    std::ofstream outfile;
    outfile.open("HeatSystem.txt");

    if (!outfile.is_open())
        throw std::runtime_error("Error! output file not open");

    // print the start and '#' so python ignores line
    outfile << "# Start @ 0" << std::endl;
    // write initial data
    write(outfile);
    // to count how many times run

    while(time_elapsed <= tf){
        update();
        time_elapsed += dt;
        total_runs++;
        outfile << "#" << time_elapsed << std::endl;
        write(outfile);
    }
    std::cout << "total_runs=" << total_runs << std::endl;
    outfile.close();
}

auto HeatSystem::write(std::ofstream &outfile) -> void {
    int x, y;
    x = system->get_width();
    y = system->get_height();
    for (int i = 0; i < y; i+=1) {
        for (int j = 0; j < x; j+=1) {
            outfile << system->get(i, j)<<" ";
        }
        outfile << "\n";
    }
    //outfile << "#second" << std::endl;
}

// steady state
// no generation
auto HeatSystem::update() -> void {
    Matrix new_system(system->get_width(),system->get_height());
    for (int i = 1; i < system->get_height()-1; i+=1) {
        for (int j = 1; j < system->get_width()-1;j+=1) {
            double new_temp = gamma * (system->get(i + 1, j) + system->get(i - 1, j) + system->get(i, j + 1)
                                       + system->get(i, j - 1) - (4 * system->get(i, j))) + system->get(i, j);
            new_system.set(i, j, new_temp);
            new_system.set(3,3, initialT);
        }
    }
    system.reset(nullptr);
    system = std::make_unique<Matrix>(new_system);
}
