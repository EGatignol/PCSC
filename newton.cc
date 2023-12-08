#include "newton.hh"
/* --------------------------------------------------------------------------- */

Newton::Newton(Eigen::VectorXd x, bool aitken, const double tol, const int maxit): FixedPoint(x,aitken,tol,maxit)
{}
/* --------------------------------------------------------------------------- */

std::string Newton::getName() {
    return "Fixed point using Newton Method";
};

/* --------------------------------------------------------------------------- */

Eigen::VectorXd Newton::NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX){
    auto facto = f.DerivedFunc(previousX).fullPivLu();
    if (facto.isInvertible() == false) {
        throw std::runtime_error("Singular matrix");
    }
    Eigen::VectorXd dX = facto.solve(-f.Func(previousX));
    Eigen::VectorXd newX = previousX + dX;

    return newX;
}



/* --------------------------------------------------------------------------- */