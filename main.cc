
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
    // first example (R to R): F1(x) = x²-1
    std::vector<vector<double>> coeffs_F1 = {{-1, 0, 1}};
    Polynomial1ToN F1(coeffs_F1, 1, 1);
    // second example (R to R³): F2(x): f1(x)=3x³+2, f2(x)=x⁴-(1/2)x²
    std::vector<vector<double>> coeffs_F2 = {{2, 0, 0, 3},{0,0,-0.5,0,1}};
    Polynomial1ToN F2(coeffs_F2, 2, 1);

// Methods to find roots for F1
    // x initial
    Eigen::VectorXd X_initial_F1(1);
    X_initial_F1 << 3;
    // x previous for the ClassicChord
    Eigen::VectorXd  X_previous_F1(1);
    X_previous_F1 << 6;
    // Interval initial for the bisection
    std::pair<double,double> Inter_init_F1(0.2, 13.1);
    // Classic chord with Aitken:
    ClassicChord ClassicChord_F1(X_previous_F1,X_initial_F1, true, 10e-10,100);
    // Bisection:
    Bissection Bisection_F1( Inter_init_F1, 10e-10, 100);
    // Newton without Aitken:
    Newton Newton_F1(X_initial_F1, false, 10e-10,100);

// Methods to find roots for F2
    // x initial
    Eigen::VectorXd X_initial_F2(1);
    X_initial_F2 << 15.3;
    // x previous for the ClassicChord
    Eigen::VectorXd  X_previous_F2(1);
    X_previous_F2 << -3.5;
    // Classic chord with Aitken:
    ClassicChord ClassicChord_F2(X_previous_F2,X_initial_F2, true, 10e-10,100);
    // Newton without Aitken:
    Newton Newton_F2(X_initial_F2, false, 10e-10,100);

// Results of the methods for F1
    ResultMethod Results_ClassicChord_F1 = ClassicChord_F1.MethodFindRoot(F1);
    ResultMethod Results_Bisection_F1 = Bisection_F1.MethodFindRoot(F1);
    ResultMethod Results_Newton_F1 = Newton_F1.MethodFindRoot(F1);
    std::cout << " F1: " << Results_ClassicChord_F1.NameMethod <<": X_final = " << Results_ClassicChord_F1.x_final << ", F1(X_final) = " << Results_ClassicChord_F1.fvalue[Results_ClassicChord_F1.fvalue.size()-1] << std::endl;
    std::cout << " F1: " << Results_Bisection_F1.NameMethod <<": X_final = " << Results_Bisection_F1.x_final << ", F1(X_final) = " << Results_Bisection_F1.fvalue[Results_Bisection_F1.fvalue.size()-1] << std::endl;
    std::cout << " F1: " << Results_Newton_F1.NameMethod <<": X_final = " << Results_Newton_F1.x_final << ", F1(X_final) = " << Results_Newton_F1.fvalue[Results_Newton_F1.fvalue.size()-1] << std::endl;

// Results of the methods for F2
    ResultMethod Results_ClassicChord_F2 = ClassicChord_F2.MethodFindRoot(F2);
    ResultMethod Results_Newton_F2 = Newton_F2.MethodFindRoot(F2);
    std::cout << " F2: " << Results_ClassicChord_F2.NameMethod <<": X_final = " << Results_ClassicChord_F2.x_final << ", F2(X_final) = " << Results_ClassicChord_F2.fvalue[Results_ClassicChord_F2.fvalue.size()-1] << std::endl;
    std::cout << " F2: " << Results_Newton_F2.NameMethod <<": X_final = " << Results_Newton_F2.x_final << ", F2(X_final) = " << Results_Newton_F2.fvalue[Results_Newton_F2.fvalue.size()-1] << std::endl;

    return EXIT_FAILURE;
}