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
  FixedPoint(Eigen::VectorXd x,bool aitken, const double tol,const int maxit);
  //! Documentation TODO
  virtual Eigen::VectorXd NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX);
  //! Documentation TODO
  ResultMethod MethodFindRoot(Function &f);
  //! Documentation TODO
  Eigen::VectorXd Aitken(Function &f, Eigen::VectorXd X, Eigen::VectorXd previouspreviousX);


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

protected:

  //!Documentation TODO
  std::string nameMethod;
  //!Documentation TODO
  Eigen::VectorXd x_initial;
  //!Documentation TODO
  Eigen::VectorXd x_previous;
  //!Documentation TODO
  bool UseAitken;


};

/* -------------------------------------------------------------------------- */
#endif //__FIXED_POINT__HH__
