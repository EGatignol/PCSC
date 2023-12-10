#include "newton.hh"
/* --------------------------------------------------------------------------- */

Newton::Newton(Eigen::VectorXd x, bool aitken, const double tol, const int maxit): FixedPoint(x,aitken,tol,maxit)
{}
/* --------------------------------------------------------------------------- */

std::string Newton::getName() {
    if (UseAitken)
    {
        return "Fixed point using Newton Method combine with Aitken";
    }
    else
    {
        return "Fixed point using Newton Method";
    }
};

/* --------------------------------------------------------------------------- */

Eigen::VectorXd Newton::NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX){
    auto facto = f.DerivedFunc(previousX).fullPivLu();
    if (facto.rows()!= f.Func(previousX).size()) {
        throw std::runtime_error("Dimensional problem for solving the linear system");
    }
    Eigen::VectorXd dX = facto.solve(-f.Func(previousX));
    Eigen::VectorXd newX = previousX + dX;

    return newX;
}



/* --------------------------------------------------------------------------- */