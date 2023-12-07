
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
// Files for the function class
#include "polynomial_1_to_n.hh"
// Files for the find-root class
#include "bissection.hh"
#include "classic_chord.hh"
#include "fixed_point.hh"
#include "newton.hh"
// File for Result_method class
#include "result_method.hh"
using namespace std;

int main(int argc, char ** argv){

// Define some functions
// first example: f(x) = x²-1
std::vector<vector<double>> coeffs_F1 = {{-1, 0, 1}};
Polynomial1ToN F1(coeffs_F1, 1, 1);

  return EXIT_FAILURE;
}