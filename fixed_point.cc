#include "fixed_point.hh"
/* -------------------------------------------------------------------------- */

Eigen::VectorXd FixedPoint::NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX){
    return previousX;
}

/* --------------------------------------------------------------------------- */

ResultMethod FixedPoint::MethodFindRoot(Function &f){

    int iteration=0;
    Eigen::VectorXd actualX = x_initial;
    Eigen::VectorXd lastX = x_previous;
    std::vector<Eigen::VectorXd> feval;
    feval.reserve(MaxIter);
    auto actualfeval=f.Func(actualX);
    auto previousfeval=f.Func(actualX);
    auto residu = (previousfeval-actualfeval).norm() + 2*tolerance;
    auto newX = actualX;

    while ((residu>tolerance) && (iteration<MaxIter))
    {

        if (UseAitken)
        {
            newX = Aitken(f, actualX, lastX);
        }
        else
        {
            newX = NextX(f, actualX, lastX);
            for (int i = 0; i < newX.size(); ++i) {
                std::cout << newX[i] << " ";
                std::cout.flush();
            }
        }

        if (newX == lastX)
        {
            break;
        }

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

Eigen::VectorXd FixedPoint::Aitken(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX)
{
     auto x1 = NextX(f, previousX, previouspreviousX);
     auto x2 = NextX(f,x1, previousX);

     Eigen::VectorXd denominator = x2-2*x1+previousX;

    try {
        if ((abs(denominator.array()) > epsilon).any()) {
            auto indexComponent = denominator.array()> epsilon;
            Eigen::VectorXd newX = indexComponent.select(x2-((x2-x1).cwiseAbs2()).cwiseQuotient(denominator),previousX);
            return newX;
        } else {
            throw std::runtime_error("denominator is too small");
        }
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return previousX;
    }

}

/* --------------------------------------------------------------------------- */

FixedPoint::FixedPoint(Eigen::VectorXd x, bool aitken, const double tol, const int maxit): FindRoot(tol, maxit)
{
    UseAitken=aitken;
    x_initial=x;
    x_previous = x;
    nameMethod= "Fixed Point";
}

/* --------------------------------------------------------------------------- */
