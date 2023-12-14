#include "fixed_point.hh"
/* -------------------------------------------------------------------------- */

Eigen::VectorXd FixedPoint::NextX(Function &f, Eigen::VectorXd previousX){

    Eigen::VectorXd nextX=previousX;

    try{
        if(f.dimX!=f.dimF){
            //throw error if the dimensions are not suitable
            throw std::invalid_argument("To use the fixedpoint method, dimension of input need to be equal to the function dimension.");
        }
    }catch (const std::invalid_argument& e){
        std::cerr << e.what() <<std::endl;
        return nextX;
    }
    try {
        //check if a function for fixed point exists
        nextX=f.FuncFixedPoint(previousX);
    }catch (const std::invalid_argument& e){
        std::cerr << e.what() << std::endl;
        return nextX;
    }
    return nextX;
}

/* --------------------------------------------------------------------------- */

std::string FixedPoint::getName(){
    // set the name of the method, considering the possible use of Aitken
    if (UseAitken)
    {
        return "Fixed Point combined with Aitken";
    }
    else
    {
        return "Fixed Point";
    }
}

/* --------------------------------------------------------------------------- */

ResultMethod FixedPoint::MethodFindRoot(Function &f){
    //check if dimensions are suitable between the function and the size of input x
    if (f.dimX!=x_initial.size()){
        throw std::invalid_argument("x initial and function don't have the same dimension");
    }

    //Initialization of the variables
    int iteration=0;
    Eigen::VectorXd actualX = x_initial;
    Eigen::VectorXd lastX = x_initial;

    std::vector<Eigen::VectorXd> feval; // vector containing the evaluation of the function at each step
    feval.reserve(MaxIter); //reserve space for it

    // creates variables of evaluation in prevision of residue computation
    auto actualfeval=f.Func(actualX);
    auto previousfeval=f.Func(actualX);

    feval.push_back(actualfeval);

    auto residu = 2*tolerance; // set initial residue in order to satisfy the first while condition
    auto newX = actualX;

    // iterative process : 2 conditions to satisfy
    // - number of iteration is capped
    // - an error threshold is accepted
    while ((residu>tolerance) && (iteration<MaxIter))
    {

        if (UseAitken)
        {
            newX = Aitken(f, actualX) ;
        }
        else
        {
            newX = NextX(f, actualX);
        }
        // check if the iterative process improves the quality of the solution.
        // in some cases, for example when the denominator is too small, and so the division is not feasible,
        // NextX return the lastX (arbitrary choice). The loop is left in this case.
        if (newX == lastX)
        {
            break;
        }

        // Update variables for the next iteration
        lastX=actualX;
        actualX=newX;
        iteration++;
        previousfeval=actualfeval;
        actualfeval=f.Func(actualX);
        residu=(previousfeval-actualfeval).norm();

        // store the function evaluation
        feval.push_back(actualfeval);
    };
    // get the name of the method for result reporting
    std::string nameMethod = getName();

    // create a ResultMethod object by calling the constructor
    ResultMethod Results(nameMethod, actualX, feval);
    return Results;
}


/* --------------------------------------------------------------------------- */

Eigen::VectorXd FixedPoint::Aitken(Function &f, Eigen::VectorXd previousX)
{
    auto currentX=previousX;
    auto newX=previousX;
    auto residu = 2*tolerance;
    int iter=0;

    // Apply Aitken method :
    while ((residu>tolerance) && (iter<10))
    {
        // computation of 2 consecutive steps
        auto x1 = NextX(f, currentX);
        auto x2 = NextX(f,x1);


        Eigen::VectorXd denominator = x2-2*x1+currentX;
        // use an exception to control the value of each denominator
        try {
            if ((abs(denominator.array()) > epsilon).any()) {
                // compute a vector containing True/False for each component of the vector
                // - True : the value is greater than epsilon (in absolute)
                // - False : the value is lower than epsilon (in absolute)
                auto indexComponent = abs(denominator.array())> epsilon;

                // Performs the Aitken iteration for the True components of "indexComponent"
                // For the False components, we keep the initial value of the vector.
                newX = indexComponent.select(x2-((x2-x1).cwiseAbs2()).cwiseQuotient(denominator),currentX);
            } else {
                // throw an error if all the component are lower than epsilon
                throw std::runtime_error("denominator is too small, early stop of the iteration method");
            }
        } catch (const std::runtime_error& e) {

            // In order to not stop completely the algo (because we may have already computed few steps)
            // the error is printed and we return the initial approx of the root
            // this return allow us to break the while in MethodsFindRoot (look at the method above)
            std::cerr << e.what() << std::endl;
            return currentX;
        }
        // update of residue and number of iteration
        iter++;
        residu=(f.Func(currentX)-f.Func(newX)).norm();
    }
    return newX;
}

/* --------------------------------------------------------------------------- */

FixedPoint::FixedPoint(Eigen::VectorXd x, bool aitken, const double tol, const int maxit): FindRoot(tol, maxit)
{
    UseAitken=aitken;
    x_initial=x;
}

/* --------------------------------------------------------------------------- */
