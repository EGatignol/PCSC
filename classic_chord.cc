#include "classic_chord.hh"
/* -------------------------------------------------------------------------- */

Eigen::VectorXd ClassicChord::NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX){

    auto chordparam = (previousX-previouspreviousX).cwiseQuotient(f.Func(previousX)-f.Func(previouspreviousX));

    auto newX= previousX-chordparam.cwiseProduct(f.Func(previousX));

    return newX;
    }

}



/* --------------------------------------------------------------------------- */


