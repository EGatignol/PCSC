#ifndef __FIXED_POINT__HH__
#define __FIXED_POINT__HH__

/* -------------------------------------------------------------------------- */
#include "find_root.hh"

/** \brief FixedPoint is derived from FindRoot (public). This class covers the general fixed-point methods.
 * Daughter classes will be derived from this class to manage special fixed-point cases.
 * Valid for function from R^M to R^M.
 */

class FixedPoint: public FindRoot{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:
  //! Constructor
  FixedPoint(Eigen::VectorXd x,bool aitken, const double tol,const int maxit);
  /*!
   * @param f class function containing the evaluation of the function and its derivative.
   * @param previousX the starting approximation of the root.
   * @param previouspreviousX the previous starting approximation of the root.
   * @return a new approximation of the root
   *
   * This methods performs one step of the iterative fixed-point method
   */
  virtual Eigen::VectorXd NextX(Function &f, Eigen::VectorXd previousX);
  //! Comes from the base class and is overridden to be suitable for the fixed point case.
  ResultMethod MethodFindRoot(Function &f) override ;
  //! Performs Aitken in addition to the fixed-point iteration.
  Eigen::VectorXd Aitken(Function &f, Eigen::VectorXd previousX);
  
protected:

    //! From the base class, give access to the name of the method
    virtual std::string getName();

  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

protected:

  //! Initial value of the root approximation
  Eigen::VectorXd x_initial;
  //! Boolean that decides if Aitken is used
  bool UseAitken;


};

/* -------------------------------------------------------------------------- */
#endif //__FIXED_POINT__HH__
