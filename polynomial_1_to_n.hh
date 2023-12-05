#ifndef __POLYNOMIAL_1_TO_N__HH__
#define __POLYNOMIAL_1_TO_N__HH__

/* -------------------------------------------------------------------------- */
#include "function.hh"

/**
  * Documentation TODO
  */

class Polynomial1ToN: public Function{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  // Constructor:
  Polynomial1ToN(Eigen::Matrix<double,-1,-1> coeffs, const int dim_F, const int dim_X);
  //! Documentation TODO
  Eigen::Matrix<double, -1, 1> Func(Eigen::VectorXd X);
  //! Documentation TODO
  Eigen::Matrix<double, -1, -1> DerivedFunc(Eigen::VectorXd X);


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

private:

  //!Documentation TODO
  Eigen::Matrix<double,-1,-1> coefficients;

};

/* -------------------------------------------------------------------------- */
#endif //__POLYNOMIAL_1_TO_N__HH__
