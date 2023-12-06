#ifndef __CLASSIC_CHORD__HH__
#define __CLASSIC_CHORD__HH__

/* -------------------------------------------------------------------------- */
#include "fixed_point.hh"
#include "function.hh"

/**
  * Documentation TODO
  */

class ClassicChord: public FixedPoint{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //! Documentation TODO
  ClassicChord(Eigen::VectorXd xprev,Eigen::VectorXd xinit, bool aitken, const double tol, const int maxit);
  //! Documentation TODO
  Eigen::VectorXd NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX);

};

/* -------------------------------------------------------------------------- */
#endif //__CLASSIC_CHORD__HH__
