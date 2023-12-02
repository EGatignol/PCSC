#ifndef __NEWTON__HH__
#define __NEWTON__HH__

/* -------------------------------------------------------------------------- */
#include <vector>
#include "fixed_point.hh"
#include "function.hh"

/**
  * Documentation TODO
  */

class Newton: public FixedPoint{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //! Documentation TODO
  Eigen::VectorXd NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX);

};

/* -------------------------------------------------------------------------- */
#endif //__NEWTON__HH__
