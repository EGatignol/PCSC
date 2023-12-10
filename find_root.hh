#ifndef __FIND_ROOT__HH__
#define __FIND_ROOT__HH__

/* -------------------------------------------------------------------------- */
#include <Eigen/Core>
#include "result_method.hh"
#include "function.hh"
#include <Eigen/Lu>
using namespace Eigen;

/** \brief FindRoot is the base class for all methods used to calculate the root of a function
  */

class FindRoot{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //! Constructor, allows setting the tolerance and the maximum number of iterations
  FindRoot(double tol,int maxit);
  /*!
   * @param f a reference to the Function class
   * @return a ResultMethod object
   MethodFindRoot is declared pure virtual and is overridden for each method used.
   */
  virtual ResultMethod MethodFindRoot(Function &f)=0;

protected:

  //! Give access to the name of the method used. is pure virtual in this class and is defined for each iterative method.
  virtual std::string getName()=0;

  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

protected:

  //! Maximum number of iterations
  int MaxIter;
  //! Accepted error to the root approximation
  double tolerance;
  //! Minimum value for the denominator
  const double epsilon = 10e-16;

};

/* -------------------------------------------------------------------------- */
#endif //__FIND_ROOT__HH__
