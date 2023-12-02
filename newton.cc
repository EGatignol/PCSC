#include "newton.hh"
/* -------------------------------------------------------------------------- */

Eigen::VectorXd Newton::NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX){
    auto facto = f.DerivedFunc(previousX).fullPivLu();
    std::vector<double> dX = facto.solve(-f.Func(previousX));

    Eigen::VectorXd newX = previousX + dX;

    return newX;
}



/* --------------------------------------------------------------------------- */


