#include "classic_chord.hh"

/* --------------------------------------------------------------------------- */

ClassicChord::ClassicChord(Eigen::VectorXd xprev,Eigen::VectorXd xinit, bool aitken, const double tol, const int maxit):FixedPoint(xinit,aitken,tol,maxit)
{
    x_previous=xprev;
}

/* -------------------------------------------------------------------------- */
std::string ClassicChord::getName() {
    return "Fixed point using classic chord";
}
/* -------------------------------------------------------------------------- */

Eigen::VectorXd ClassicChord::NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX) {
    if (f.dimX != 1){
        throw std::invalid_argument("Classic chord: x dimension must be 1. If the function if Rn to Rm with only one variable per image dimension, you can use classic chord dimension per dimension.");
    }
    Eigen::VectorXd denominator = f.Func(previousX) - f.Func(previouspreviousX);
    try {
        if ((abs(denominator.array()) > epsilon).any()) {
            auto indexComponent = abs(denominator.array())> epsilon;
            auto chordparam = indexComponent.select((previousX - previouspreviousX).cwiseQuotient(denominator),Eigen::VectorXd::Zero(previousX.size()));
            Eigen::VectorXd newX= previousX-chordparam.cwiseProduct(f.Func(previousX));
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


