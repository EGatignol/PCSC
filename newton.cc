#include "newton.hh"
/* -------------------------------------------------------------------------- */

std::vector<double> NextX(Function &f, std::vector<double> previousX){
    auto facto = f.DerivedFunc(previousX).fullPivLu();
    std::vector<double> X = facto.solve(-f.Func(previousX));
    return X;
}



/* --------------------------------------------------------------------------- */


