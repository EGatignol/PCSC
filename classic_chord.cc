#include "classic_chord.hh"

/* --------------------------------------------------------------------------- */

ClassicChord::ClassicChord(Eigen::VectorXd xprev,Eigen::VectorXd xinit, bool aitken, const double tol, const int maxit):FixedPoint(xinit,aitken,tol,maxit)
{
    nameMethod= "Fixed Point using classic chord";
    x_previous=xprev;
}

/* -------------------------------------------------------------------------- */

Eigen::VectorXd ClassicChord::NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX) {

    try {
        if (((f.Func(previousX) - f.Func(previouspreviousX)).array() > epsilon).all()) {
            auto chordparam = (previousX - previouspreviousX).cwiseQuotient(f.Func(previousX) - f.Func(previouspreviousX));
            auto newX= previousX-chordparam.cwiseProduct(f.Func(previousX));
            return newX;
        } else {
            throw std::runtime_error("denominator is too small");
        }
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return previouspreviousX;
    }
}

/* --------------------------------------------------------------------------- */


