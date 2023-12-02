#ifndef __BISSECTION__HH__
#define __BISSECTION__HH__

/* -------------------------------------------------------------------------- */
#include "find_root.hh"
#include "result_method.hh"
#include "function.hh"
using namespace std;

/**
  * Documentation TODO
  */

class Bissection: public FindRoot{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  // Constructors:
  Bissection(std::pair<double,double> inter_init);
  Bissection(std::pair<double,double> inter_init, const double tol, const int max_iter, const double epsil);
  //! Documentation TODO
  ResultMethod MethodFindRoot(Function F);


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

private:

  //!Documentation TODO
  std::pair<double,double> Interval;

};

/* -------------------------------------------------------------------------- */
#endif //__BISSECTION__HH__
