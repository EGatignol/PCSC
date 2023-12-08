
#include <cstdio>
#include <cstdlib>
#include <iostream>
// Files for the function class
#include "polynomial_1_to_n.hh"
// Files for the find-root class
#include "bissection.hh"
#include "classic_chord.hh"
#include "fixed_point.hh"
#include "newton.hh"
// File for Result_method class
#include "result_method.hh"

int main(int argc, char ** argv){

// Define some functions
// first example: F1(x) = x²-1
std::vector<vector<double>> coeffs_F1 = {{-1, 0, 1}};
Polynomial1ToN F1(coeffs_F1, 1, 1);

// Methods to find roots for F1
Eigen::VectorXd X_initial_F1(1);
X_initial_F1 << 3;
Eigen::VectorXd  X_previous_F1(1);
X_previous_F1 << 6;
ClassicChord Newton_F1(X_previous_F1,X_initial_F1,false, 10e-5,100);
//std::pair<double,double> Inter_init_F1(0.2, 13.1);
//Bissection Bissection_F1( Inter_init_F1, 10e-10, 100);

// Results of the method for F1
ResultMethod Results_Newton_F1 = Newton_F1.MethodFindRoot(F1);
std::cout << "Root for Newton_Methods=" << Results_Newton_F1.x_final << std::endl;
std::cout << "Values of F1(x)=x2-1 during iteration=";
    for (int i = 0; i < Results_Newton_F1.fvalue.size(); ++i) {
        std::cout << Results_Newton_F1.fvalue[i] << " ";
    }
    std:cout << std::endl;
  return EXIT_FAILURE;
}