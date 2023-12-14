#ifndef GENERATEDFROMCODEGENERATOR_PLOTCONVERGENCE_H
#define GENERATEDFROMCODEGENERATOR_PLOTCONVERGENCE_H

/* -------------------------------------------------------------------------- */

#include "result_method.hh"

/** \brief Class used to visualize the possible convergence
  */

class PlotConvergence{

    /* ------------------------------------------------------------------------ */
    /* Methods                                                                  */
    /* ------------------------------------------------------------------------ */

public:
    //! plot the function evaluation at each step of the iteration method
    void getGraphConv(ResultMethod &r);
};

/* -------------------------------------------------------------------------- */

#endif //GENERATEDFROMCODEGENERATOR_PLOTCONVERGENCE_H
