#include "newton.hh"
/* --------------------------------------------------------------------------- */

Newton::Newton(Eigen::VectorXd x, bool aitken, const double tol, const int maxit): FixedPoint(x,aitken,tol,maxit)
{}
/* --------------------------------------------------------------------------- */

std::string Newton::getName() {
    // set the name of the method, considering the possible use of Aitken
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

Eigen::VectorXd Newton::NextX(Function &f, Eigen::VectorXd previousX){
    // Compute LU decomposition of the Jacobian Matrix
    auto facto = f.DerivedFunc(previousX).fullPivLu();
    // check the dimension before the linear system is solved
    if (facto.rows()!= f.Func(previousX).size()) {
        throw std::runtime_error("Dimensional problem for solving the linear system");
    }
    // Solve the linear system
    Eigen::VectorXd dX = facto.solve(-f.Func(previousX));
    // Update the value of the root approximation
    Eigen::VectorXd newX = previousX + dX;

    return newX;
}



/* --------------------------------------------------------------------------- */