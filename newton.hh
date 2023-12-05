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
  Newton(Eigen::VectorXd x,bool aitken, const double tol,const int maxit);
  //! Documentation TODO
  Eigen::VectorXd NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX);


};

/* -------------------------------------------------------------------------- */
#endif //__NEWTON__HH__
