#include "fixed_point.hh"
/* -------------------------------------------------------------------------- */

Eigen::VectorXd FixedPoint::NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX){

}

/* --------------------------------------------------------------------------- */

ResultMethod FixedPoint::MethodFindRoot(function &f){
    double realtol = tolerance*sqrt(x_initial.size());
    int iteration=0;
    Eigen::VectorXd actualX = x_initial;
    Eigen::VectorXd lastX = x_previous;
    std::vector<Eigen::VectorXd> feval;
    feval.reserve(MaxIter);
    auto actualfeval=f.Func(actualX);
    while ((actualfeval.norm()>realtol) && (iteration<MaxIter))
    {
        auto newX = NextX(f, actualX, lastX);
        lastX=actualX;
        actualX=newX;
        iteration++;

        actualfeval=f.Func(actualX);
        feval.push_back(actualfeval)
    }
    ResultMethod Results(nameMethod, actualX, feval);
    return Results;
}


/* --------------------------------------------------------------------------- */

FixedPoint::FixedPoint(Eigen::VectorXd x, bool aitken, const double tol, const int maxit) {
    FindRoot(tol,maxit);
    UseAitken=aitken;
    x_initial=x;
    nameMethod = "Fixed Point";
}

/* --------------------------------------------------------------------------- */
