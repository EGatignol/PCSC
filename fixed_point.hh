#ifndef __FIXED_POINT__HH__
#define __FIXED_POINT__HH__

/* -------------------------------------------------------------------------- */
#include "find_root.hh"

/**
  * Documentation TODO
  */

class FixedPoint: public FindRoot{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //! Documentation TODO
  virtual std:vector<double> NextX(Function unnamed, std::vector<double> unnamed, std::vector<double> unnamed);
  //! Documentation TODO
  ResultMethod MethodFindRoot(Function unnamed);


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

protected:

  //!Documentation TODO
  std::vector<double> x_initial;
  //!Documentation TODO
  Bool UseAitken;

};

/* -------------------------------------------------------------------------- */
#endif //__FIXED_POINT__HH__
