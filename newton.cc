#include "newton.hh"
/* --------------------------------------------------------------------------- */

Newton::Newton(Eigen::VectorXd x, bool aitken, const double tol, const int maxit) {
    FindRoot(tol,maxit);
    UseAitken=aitken;
    x_initial=x;
    nameMethod = "Fixed point using Newton method";

/* --------------------------------------------------------------------------- */

Eigen::VectorXd Newton::NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX){
    auto facto = f.DerivedFunc(previousX).fullPivLu();
    std::vector<double> dX = facto.solve(-f.Func(previousX));

    Eigen::VectorXd newX = previousX + dX;

    return newX;
}



/* --------------------------------------------------------------------------- */