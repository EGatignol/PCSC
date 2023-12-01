#ifndef __BISSECTION__HH__
#define __BISSECTION__HH__

/* -------------------------------------------------------------------------- */
#include "find_root.hh"

/**
  * Documentation TODO
  */

class Bissection: public FindRoot{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //! Documentation TODO
  ResultMethod MethodFindRoot(Function unnamed);


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

private:

  //!Documentation TODO
  std::pair<double,double> Interval;

};

/* -------------------------------------------------------------------------- */
#endif //__BISSECTION__HH__
