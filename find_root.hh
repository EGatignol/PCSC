#ifndef __FIND_ROOT__HH__
#define __FIND_ROOT__HH__

/* -------------------------------------------------------------------------- */
#include <Eigen/Core>
#include "result_method.hh"
#include "function.hh"
#include <Eigen/Lu>

using namespace Eigen;
/**
  * Documentation TODO
  */

class FindRoot{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  FindRoot(const double tol,const int maxit);
  //! Documentation TODO
  virtual ResultMethod MethodFindRoot(Function &f)=0;


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

protected:

  //!Documentation TODO
  int MaxIter;
  //!Documentation TODO
  double tolerance;
  //!Documentation TODO
  const double epsilon = 10e-16;

};

/* -------------------------------------------------------------------------- */
#endif //__FIND_ROOT__HH__
