#ifndef __FIXED_POINT__HH__
#define __FIXED_POINT__HH__

/* -------------------------------------------------------------------------- */
#include "find_root.hh"

/**
  * Documentation TODO
  */

class FixedPoint: public FindRoot{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:
  //! Documentation TODO
  FixedPoint(std::vector x,bool aitken, const double tol,const int maxit);
  //! Documentation TODO
  virtual Eigen::VectorXd NextX(Function unnamed, Eigen::VectorXd unnamed, Eigen::VectorXd unnamed);
  //! Documentation TODO
  ResultMethod MethodFindRoot(Function unnamed);


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

protected:

  //!Documentation TODO
  Eigen::VectorXd x_initial;
  //!Documentation TODO
  bool UseAitken;


};

/* -------------------------------------------------------------------------- */
#endif //__FIXED_POINT__HH__
