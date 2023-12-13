#include "CSVReaderPolynome.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>

Polynomial1ToN CSVReaderPolynome::Read(const std::string& NameFile){
    std::ifstream read_file(NameFile);
    assert(read_file.is_open());

    std::vector<std::vector<double>> coeff;

    std::string line;
    while (std::getline(read_file, line)) {
        std::istringstream ss(line);
        std::vector<double> lineFunc;
        std::string value;

        while (std::getline(ss, value, ',')) {
            lineFunc.push_back(std::stod(value));
        }

        coeff.push_back(lineFunc);
    }
    read_file.close();
}