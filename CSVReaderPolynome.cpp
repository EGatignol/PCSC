#include "CSVReaderPolynome.h"
#include <cassert>
#include <iostream>
#include <fstream>

Polynomial1ToN CSVReaderPolynome::Read(const std::string& NameFile){
    std::ifstream read_file(NameFile);
    assert(read_file.is_open());
    int dimF;
    read_file >> dimF;
    std::vector<std::vector<double>> coeff;
    int i=0;
    while (!read_file.eof())
    {
        for(int j=0; j<=dimF-1; j++){
            read_file >> 
        }
    }
    
}