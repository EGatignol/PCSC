#ifndef __RESULT_METHOD__HH__
#define __RESULT_METHOD__HH__

/* -------------------------------------------------------------------------- */

/**
  * Class to stock the results of a method to find a root for a function F;
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

  /// Constructor:
  ResultMethod(std::string Name_method, Eigen::Matrix<double,-1,1> x, std::vector<Eigen::VectorXd> Value_f_by_iteration);

  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  /// Name of the method used to get the results
  std::string NameMethod;
  /// The value of x at the end of the iterations
  Eigen::Matrix<double,-1,1> x_final;
  /// The value of the function during the iterations
  std::vector<Eigen::VectorXd> fvalue;

};

/* -------------------------------------------------------------------------- */
#endif //__RESULT_METHOD__HH__
