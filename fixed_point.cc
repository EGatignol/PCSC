#include "fixed_point.hh"
/* -------------------------------------------------------------------------- */

Eigen::VectorXd FixedPoint::NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX){

}

/* --------------------------------------------------------------------------- */

ResultMethod FixedPoint::MethodFindRoot(function &f){

    int iteration=0;
    Eigen::VectorXd actualX = x_initial;
    Eigen::VectorXd lastX = x_previous;
    std::vector<Eigen::VectorXd> feval;
    feval.reserve(MaxIter);
    auto actualfeval=f.Func(actualX);
    auto previousfeval=f.Func(actualX);
    auto residu = (previousfeval-actualfeval).norm() + 2*realtol;

    while ((residu>tolerance) && (iteration<MaxIter))
    {
        auto newX = NextX(f, actualX, lastX);
        lastX=actualX;
        actualX=newX;
        iteration++;

        previousfeval=actualfeval;
        actualfeval=f.Func(actualX);
        residu=(previousfeval-actualfeval).norm();

        feval.push_back(actualfeval);
    };
    ResultMethod Results(nameMethod, actualX, feval);
    return Results;
}


/* --------------------------------------------------------------------------- */

FixedPoint::FixedPoint(Eigen::VectorXd x, bool aitken, const double tol, const int maxit): FindRoot(tol, maxit)
{
    UseAitken=aitken;
    x_initial=x;
    nameMethod= "Fixed Point";
}

/* --------------------------------------------------------------------------- */
