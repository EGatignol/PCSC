#ifndef __RESULT_METHOD__HH__
#define __RESULT_METHOD__HH__

/* -------------------------------------------------------------------------- */

/**
  * Documentation TODO
  */
#include <iostream>
#include <vector>
using namespace std;

class ResultMethod{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  // Constructor:
  ResultMethod(std::string Name_method, vector<double> x, std::vector<std::vector<double>> Value_f_by_iteration);
  //! Documentation TODO
  gnuplot GraphConvergence();


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //!Documentation TODO
  std::string NameMethod;
  //!Documentation TODO
  std::vector<double> x_final;
  //!Documentation TODO
  std::vector<std::vector<double>> fvalue;

};

/* -------------------------------------------------------------------------- */
#endif //__RESULT_METHOD__HH__
