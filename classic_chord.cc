#include "classic_chord.hh"

/* --------------------------------------------------------------------------- */

ClassicChord::ClassicChord(Eigen::VectorXd xprev,Eigen::VectorXd xinit, bool aitken, const double tol, const int maxit):FixedPoint(xinit,aitken,tol,maxit)
{
    x_previous=xprev;
}

/* -------------------------------------------------------------------------- */
std::string ClassicChord::getName() {
    // set the name of the method, considering the possible use of Aitken
    if (UseAitken)
    {
        return "Fixed point using classic chord combined with Aitken";
    }
    else
    {
        return "Fixed point using classic chord";
    }
}
/* -------------------------------------------------------------------------- */

Eigen::VectorXd ClassicChord::NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX) {
    // check the dimension of the input function, throw a message and stop the program if the conditions aren't satisfied.
    if (f.dimX != 1 || f.dimF!=1 ){
        throw std::invalid_argument("Classic chord: dimension of input and function must be equal to 1.");
    }
    Eigen::VectorXd denominator = f.Func(previousX) - f.Func(previouspreviousX);
    try {
        // verify the value of the denominator
        if ((abs(denominator.array()) > epsilon).any()) {
            // perform the classic chord algo if denominator is suitable
            auto chordparam = (previousX - previouspreviousX).cwiseQuotient(denominator);
            Eigen::VectorXd newX= previousX-chordparam.cwiseProduct(f.Func(previousX));
            return newX;
        } else {
            // throw an error if the component is lower than epsilon
            throw std::runtime_error("denominator is too small");
        }
    } catch (const std::runtime_error& e) {
        // In order to not stop completely the algo (because we may have already computed few steps)
        // the error is printed and we return the initial approx of the root
        // this return allow us to break the while in MethodsFindRoot (look at the method above)
        std::cerr << e.what() << std::endl;
        return previousX;
    }
}

/* --------------------------------------------------------------------------- */


