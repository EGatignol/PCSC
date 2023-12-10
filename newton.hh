#ifndef __NEWTON__HH__
#define __NEWTON__HH__

/* -------------------------------------------------------------------------- */
#include <vector>
#include "fixed_point.hh"
#include "function.hh"

/**\brief Daughter class of FixedPoint. Considers a special case of fixed point : the Newton method.
  * Can find a root for a function f from Rn to Rm.
  */

class Newton: public FixedPoint{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //! Constructor
  Newton(Eigen::VectorXd x,bool aitken, const double tol,const int maxit);
  //! From FixedPoint, is overridden to be applied in the specific case of Newton iterative method
  //! Computes one step of the iterative method
  Eigen::VectorXd NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX);
protected:
  //! From the base class, give access to the name of the method
  std::string getName() override;

};

/* -------------------------------------------------------------------------- */
#endif //__NEWTON__HH__
