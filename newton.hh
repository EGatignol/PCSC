#ifndef __NEWTON__HH__
#define __NEWTON__HH__

/* -------------------------------------------------------------------------- */
#include "fixed_point.hh"

/**
  * Documentation TODO
  */

class Newton: public FixedPoint{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //! Documentation TODO
  std:vector<double> NextX(Function unnamed, std::vector<double> unnamed, std::vector<double> unnamed);

};

/* -------------------------------------------------------------------------- */
#endif //__NEWTON__HH__
