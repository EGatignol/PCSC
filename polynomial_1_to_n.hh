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

  //! Documentation TODO
  Eigen::Matrix<double, -1, 1> Func(std::vector<double> X);
  //! Documentation TODO
  Eigen::Matrix<double, -1, -1> DerivedFunc(std::vector<double> X);


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

private:

  //!Documentation TODO
  std::vector<vector<double>> coefficients;

};

/* -------------------------------------------------------------------------- */
#endif //__POLYNOMIAL_1_TO_N__HH__
