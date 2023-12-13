#ifndef __BISSECTION__HH__
#define __BISSECTION__HH__

/* -------------------------------------------------------------------------- */
#include "find_root.hh"
#include "result_method.hh"
#include "function.hh"
using namespace std;

/**
  * FindRoot daughter class. This class use the bisection method to
  * find a root for a function f from R to R.
  */

class Bissection: public FindRoot{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  /// Constructors:
  Bissection(std::pair<double,double> inter_init, double tol, int max_iter);

  /**
   * Method coming from FindRoot that applies the bisection
   * method to find a root for the Function F. Returns a ResultMethod object.
   */
  ResultMethod MethodFindRoot(Function &F);

protected:

  /// Method coming from FindRoot, that give the name of the function, here "bisection".
  std::string getName();

  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

private:

  /// Initial Interval for the bisection. Must be such that f(a)*f(b)<0.
  std::pair<double,double> Interval;

};

/* -------------------------------------------------------------------------- */
#endif //__BISSECTION__HH__
