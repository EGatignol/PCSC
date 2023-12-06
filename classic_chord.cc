#include "classic_chord.hh"

/* --------------------------------------------------------------------------- */

ClassicChord::ClassicChord(Eigen::VectorXd xprev,Eigen::VectorXd xinit, bool aitken, const double tol, const int maxit):FixedPoint(xinit,aitken,tol,maxit)
{
    nameMethod= "Fixed Point using classic chord";
    x_previous=xprev;
}

/* -------------------------------------------------------------------------- */

Eigen::VectorXd ClassicChord::NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX) {
    auto denominator = f.Func(previousX) - f.Func(previouspreviousX);

    try {
        if ((denominator.array() > epsilon).any()) {
            auto indexComponent = denominator.array()> epsilon;
            auto chordparam = indexComponent.select((previousX - previouspreviousX).cwiseQuotient(f.Func(previousX) - f.Func(previouspreviousX)),Eigen::VectorXd::Zero(previousX.size()));
            auto newX= previousX-chordparam.cwiseProduct(f.Func(previousX));
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


