
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
#include "PlotConvergence.h"
// File for Reader class
#include "CSVReaderPolynome.h"

int main(int argc, char ** argv){
CSVReaderPolynome CSVRead;
Polynomial1ToN F1 = CSVRead.Read("Coeff_F1.csv");

double tol=10e-10;
int maxiteration=100;


// Define some functions

    int methodNumber;

    std::cout << "Enter the number of the method that you want to use\n - 1 for Bissection\n - 2 for Fixed Point\n - 3 for Newton\n - 4 for Classic Chord\n Then press enter.\n";
    std::cin >> methodNumber;

    switch(methodNumber){
        case 1: {
            double lowbound;
            double upbound;
            std::cout << "Enter the lower bound of the interval\n Then press enter.\n";
            std::cin >> lowbound;
            std::cout << "Enter the lower bound of the interval\n Then press enter.\n";
            std::cin >> upbound;
            std::pair<double, double> Interv(lowbound, upbound);
            Bissection BissectionM(Interv, tol, maxiteration);
            ResultMethod Results = BissectionM.MethodFindRoot(F1);
            PlotConvergence plotb;
            plotb.getGraphConv(Results);
            break;
        }
        case 2: {
            int vectorsize;
            std::cout << "Enter the size of the initial vector\n Then press enter. \n";
            std::cin >> vectorsize;
            Eigen::VectorXd Xin(vectorsize);
            for (int i = 0; i < vectorsize; i++) {
                std::cout << "enter the " << i + 1 << " component of the vector, then press enter\n";
                std::cin >> Xin[i];
            }
            bool aitken;
            std::cout
                    << "In addition of the fixed point, enter true if you want to use Aitken, otherwise false.\n Then press enter\n";
            std::cin >> aitken;
            FixedPoint FixedPointM(Xin, aitken, tol, maxiteration);
            ResultMethod Results_FixedPoint = FixedPointM.MethodFindRoot(F1);
            PlotConvergence plot;
            plot.getGraphConv(Results_FixedPoint);
            break;
        }
        case 3:{
            int vectorsize;
            std::cout << "Enter the size of the initial vector\n Then press enter. \n";
            std::cin >> vectorsize;
            Eigen::VectorXd Xin(vectorsize);
            for (int i = 0; i < vectorsize; i++) {
                std::cout << "enter the " << i + 1 << " component of the vector, then press enter\n";
                std::cin >> Xin[i];
            }
            bool aitken;
            std::cout << "In addition of the newton, enter true if you want to use Aitken, otherwise false.\n Then press enter\n";
            std::cin >> aitken;
            Newton NewtonM(Xin, aitken, tol, maxiteration);
            ResultMethod Results_Newton = NewtonM.MethodFindRoot(F1);
            PlotConvergence plot;
            plot.getGraphConv(Results_Newton);
            break;
        }
            ;
        case 4:{
            int vectorsize;
            std::cout << "Enter the size of the initial vector\n Then press enter. \n";
            std::cin >> vectorsize;
            Eigen::VectorXd Xin(vectorsize);
            Eigen::VectorXd Xprev(vectorsize);
            for (int i = 0; i < vectorsize; i++) {
                std::cout << "enter the " << i + 1 << " component of the initial vector, then press enter\n";
                std::cin >> Xin[i];
            }
            for (int i = 0; i < vectorsize; i++) {
                std::cout << "enter the " << i + 1 << " component of the previous vector, then press enter\n";
                std::cin >> Xprev[i];
            }
            bool aitken;
            std::cout
                    << "In addition of the classic chord, enter true if you want to use Aitken, otherwise false.\n Then press enter\n";
            std::cin >> aitken;
            Newton NewtonM(Xin, aitken, tol, maxiteration);
            ResultMethod Results_Newton = NewtonM.MethodFindRoot(F1);
            PlotConvergence plot;
            plot.getGraphConv(Results_Newton);
            break;
        }
        default:
            std::cout << "Please enter a valid method\n";
            break;
    }

    return EXIT_FAILURE;

}