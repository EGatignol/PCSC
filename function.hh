#ifndef __FUNCTION__HH__
#define __FUNCTION__HH__

/* -------------------------------------------------------------------------- */

/**
  * Class Function to create a function.
  */
#include <vector>
#include <Eigen/Core>
using namespace std;
using namespace Eigen;

class Function{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:
  /// Constructor:
  Function(int dim_F, int dim_X);
  /// Pure virtual function to evaluate the function in x.
  virtual Eigen::VectorXd Func(Eigen::VectorXd X)=0;
  /// Pure virtual function to evaluate the derivative of the function in x.
  virtual Eigen::Matrix<double, -1, -1> DerivedFunc(Eigen::VectorXd X)=0;
  /**
   * Pure virtual function to evaluate the fixed_point function x.
   * The fixed_point function for a function F is a function G s.t.
   * F(x) = 0 implies G(x)=x.
   */
  virtual Eigen::VectorXd FuncFixedPoint(Eigen::VectorXd X)=0;


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //! The dimension of X
  int dimX;
  //! The dimension of F(X)
  int dimF;

};

/* -------------------------------------------------------------------------- */
#endif //__FUNCTION__HH__
