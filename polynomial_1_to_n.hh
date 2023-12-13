#ifndef __POLYNOMIAL_1_TO_N__HH__
#define __POLYNOMIAL_1_TO_N__HH__

/* -------------------------------------------------------------------------- */
#include "function.hh"

/**
  * Function daughter class. This class is to create polynomial functions from R to R^N.
  */

class Polynomial1ToN: public Function{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  /// Constructor:
  Polynomial1ToN(std::vector<vector<double>> coeffs, int dim_F, int dim_X);
  /// Method coming from Function to evaluate the function in x.
  Eigen::VectorXd Func(Eigen::VectorXd X);
  /// Method coming from Function to evaluate the derivative function in x.
  Eigen::Matrix<double, -1, -1> DerivedFunc(Eigen::VectorXd X);
  /// Method coming from Function to evaluate the fixed_point function of F in x.
  Eigen::VectorXd FuncFixedPoint(Eigen::VectorXd X);


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

private:

  /// Coefficients of the function s.t. if f_i(x) = sum(a_{i,k}*x^k)
  /// then coefficients[i][k] = a_{i,k}.
  std::vector<vector<double>> coefficients;

};

/* -------------------------------------------------------------------------- */
#endif //__POLYNOMIAL_1_TO_N__HH__
