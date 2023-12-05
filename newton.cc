#include "newton.hh"
/* --------------------------------------------------------------------------- */

Newton::Newton(Eigen::VectorXd x, bool aitken, const double tol, const int maxit): FixedPoint(x,aitken,tol,maxit)
{
    nameMethod= "Fixed Point using Newton method";
}

/* --------------------------------------------------------------------------- */

Eigen::VectorXd Newton::NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX){
    auto facto = f.DerivedFunc(previousX).fullPivLu();
    std::vector<double> dX = facto.solve(-f.Func(previousX));

    Eigen::VectorXd newX = previousX + dX;

    return newX;
}



/* --------------------------------------------------------------------------- */