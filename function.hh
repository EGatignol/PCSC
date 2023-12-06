#ifndef __FUNCTION__HH__
#define __FUNCTION__HH__

/* -------------------------------------------------------------------------- */

/**
  * Documentation TODO
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
  // Constructor:
  Function(int dim_F, int dim_X);
  //! Documentation TODO
  virtual Eigen::VectorXd Func(Eigen::VectorXd X)=0;
  //! Documentation TODO
  virtual Eigen::Matrix<double, -1, -1> DerivedFunc(Eigen::VectorXd X)=0;


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //!Documentation TODO
  int dimX;
  //!Documentation TODO
  int dimF;

};

/* -------------------------------------------------------------------------- */
#endif //__FUNCTION__HH__
