#ifndef __FIND_ROOT__HH__
#define __FIND_ROOT__HH__

/* -------------------------------------------------------------------------- */

/**
  * Documentation TODO
  */

class FindRoot{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //! Documentation TODO
  virtual ResultMethod MethodFindRoot(Function unnamed)=0;


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

protected:

  //!Documentation TODO
  int MaxIter;
  //!Documentation TODO
  double tolerance;
  //!Documentation TODO
  double epsilon;

};

/* -------------------------------------------------------------------------- */
#endif //__FIND_ROOT__HH__
