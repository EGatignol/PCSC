#ifndef __NEWTON__HH__
#define __NEWTON__HH__

/* -------------------------------------------------------------------------- */
#include <vector>
#include "fixed_point.hh"
#include "function.hh"

/**
  * Documentation TODO
  */

class Newton: public FixedPoint{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //! Documentation TODO
  std::vector<double> NextX(Function &func, std::vector<double> previousX);

};

/* -------------------------------------------------------------------------- */
#endif //__NEWTON__HH__
