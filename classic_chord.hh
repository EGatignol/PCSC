#ifndef __CLASSIC_CHORD__HH__
#define __CLASSIC_CHORD__HH__

/* -------------------------------------------------------------------------- */
#include "fixed_point.hh"
#include "function.hh"

/**
  * Documentation TODO
  */

class ClassicChord: public FixedPoint{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //! Documentation TODO
  Eigen::VectorXd ClassicChord::NextX(Function &f, Eigen::VectorXd previousX, Eigen::VectorXd previouspreviousX);

};

/* -------------------------------------------------------------------------- */
#endif //__CLASSIC_CHORD__HH__
