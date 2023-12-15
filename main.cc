
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

    // get the polynome entered by the user from CSV file
    CSVReaderPolynome CSVRead;
    Polynomial1ToN F1 = CSVRead.Read("Coeff_F1.csv");

    // set tolerance and maximal number of iterations
    double tol=10e-10;
    int maxiteration=100;


    // ask the user to choose the method
    int methodNumber;

    std::cout << "Enter the number of the method that you want to use\n - 1 for Bissection\n - 2 for Fixed Point\n - 3 for Newton\n - 4 for Classic Chord\n Then press enter.\n";
    std::cin >> methodNumber;

    // depending on the chosen method
    // parameter associated must be entered by the user
    // then the root is computed
    switch(methodNumber){
        case 1: {
            // set lower bound and upperbound of the interval containing the expected root
            double lowbound;
            double upbound;
            std::cout << "Enter the lower bound of the interval\n Then press enter.\n";
            std::cin >> lowbound;
            std::cout << "Enter the lower bound of the interval\n Then press enter.\n";
            std::cin >> upbound;
            std::pair<double, double> Interv(lowbound, upbound);

            //construct bisection object and computation of the root
            Bissection Bisection(Interv, tol, maxiteration);
            ResultMethod Results_Bisection = Bisection.MethodFindRoot(F1);

            std::cout << Results_Bisection.NameMethod <<": X_final = " << Results_Bisection.x_final << ", F(X_final) = " << Results_Bisection.fvalue[Results_Bisection.fvalue.size()-1] << std::endl;

            PlotConvergence plot;
            plot.getGraphConv(Results_Bisection);
            break;
        }
        case 2: {
            // set the size and components of initial vector
            int vectorsize;
            std::cout << "Enter the size of the initial vector\n Then press enter. \n";
            std::cin >> vectorsize;
            Eigen::VectorXd Xin(vectorsize);
            for (int i = 0; i < vectorsize; i++) {
                std::cout << "enter the " << i + 1 << " component of the vector, then press enter\n";
                std::cin >> Xin[i];
            }
            // set the use of aitken
            bool aitken;
            std::cout
                    << "In addition of the fixed point, enter true if you want to use Aitken, otherwise false.\n Then press enter\n";
            std::cin >> aitken;

            //construct Fixedpoint object and computation of the root
            FixedPoint FixedPointM(Xin, aitken, tol, maxiteration);
            ResultMethod Results_FixedPoint = FixedPointM.MethodFindRoot(F1);

            std::cout << Results_FixedPoint.NameMethod <<": X_final = " << Results_FixedPoint.x_final << ", F(X_final) = " << Results_FixedPoint.fvalue[Results_FixedPoint.fvalue.size()-1] << std::endl;

            PlotConvergence plot;
            plot.getGraphConv(Results_FixedPoint);
            break;
        }
        case 3:{
            // set the size and components of initial vector
            int vectorsize;
            std::cout << "Enter the size of the initial vector\n Then press enter. \n";
            std::cin >> vectorsize;
            Eigen::VectorXd Xin(vectorsize);
            for (int i = 0; i < vectorsize; i++) {
                std::cout << "enter the " << i + 1 << " component of the vector, then press enter\n";
                std::cin >> Xin[i];
            }
            // set the use of aitken
            bool aitken;
            std::cout << "In addition of the newton, enter true if you want to use Aitken, otherwise false.\n Then press enter\n";
            std::cin >> aitken;

            //construct Newton object and computation of the root
            Newton NewtonM(Xin, aitken, tol, maxiteration);
            ResultMethod Results_Newton = NewtonM.MethodFindRoot(F1);

            std::cout << Results_Newton.NameMethod <<": X_final = " << Results_Newton.x_final << ", F(X_final) = " << Results_Newton.fvalue[Results_Newton.fvalue.size()-1] << std::endl;

            PlotConvergence plot;
            plot.getGraphConv(Results_Newton);
            break;
        }
            ;
        case 4:{
            // set the size and components of initial/previous vectors
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

            //construct ClassicChord object and computation of the root
            ClassicChord classicChordM(Xprev, Xin, aitken, tol, maxiteration);
            ResultMethod Results_classicChord = classicChordM.MethodFindRoot(F1);

            std::cout << Results_classicChord.NameMethod <<": X_final = " << Results_classicChord.x_final << ", F(X_final) = " << Results_classicChord.fvalue[Results_classicChord.fvalue.size()-1] << std::endl;

            PlotConvergence plot;
            plot.getGraphConv(Results_classicChord);
            break;
        }
        default:
            // if a unknown method is chosen, ask to restart
            std::cout << "Invalid method\nrerun the program with a valid method !\n ";
    }

    return EXIT_FAILURE;

}