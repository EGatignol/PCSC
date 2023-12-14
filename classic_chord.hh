#ifndef __CLASSIC_CHORD__HH__
#define __CLASSIC_CHORD__HH__

/* -------------------------------------------------------------------------- */
#include "fixed_point.hh"
#include "function.hh"

/** \brief Daughter class of FixedPoint. Considers a special case of fixed point : the classic chord method.
  * Can find a root for a function f from R to R.
  */

class ClassicChord: public FixedPoint{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //! Constructor
  ClassicChord(Eigen::VectorXd xprev,Eigen::VectorXd xinit, bool aitken, const double tol, const int maxit);
  //! From FixedPoint, is overridden to be applied in the specific case of the classic chord iterative method
  //! Computes one step of the iterative method
  Eigen::VectorXd NextX(Function &f, Eigen::VectorXd previousX) override ;
  //! get the reference of x_previous, used to read the value of x_previous
  const Eigen::VectorXd& getXprevious() {
      return x_previous;
  }

protected :

  //! From the base class, give access to the name of the method
  std::string getName() override;

  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

protected :

  //! previous value of the root approximation
  Eigen::VectorXd x_previous;
};


/* -------------------------------------------------------------------------- */
#endif //__CLASSIC_CHORD__HH__
