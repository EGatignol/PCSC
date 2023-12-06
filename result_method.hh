#ifndef __RESULT_METHOD__HH__
#define __RESULT_METHOD__HH__

/* -------------------------------------------------------------------------- */

/**
  * Documentation TODO
  */
#include <iostream>
#include <vector>
#include <Eigen/Core>
using namespace Eigen;
using namespace std;

class ResultMethod{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  // Constructor:
  ResultMethod(std::string Name_method, Eigen::Matrix<double,-1,1> x, std::vector<Eigen::VectorXd> Value_f_by_iteration);
  //! Documentation TODO
  //gnuplot GraphConvergence();


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //!Documentation TODO
  std::string NameMethod;
  //!Documentation TODO
  Eigen::Matrix<double,-1,1> x_final;
  //!Documentation TODO
  std::vector<Eigen::VectorXd> fvalue;

};

/* -------------------------------------------------------------------------- */
#endif //__RESULT_METHOD__HH__
