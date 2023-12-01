#ifndef __RESULT_METHOD__HH__
#define __RESULT_METHOD__HH__

/* -------------------------------------------------------------------------- */

/**
  * Documentation TODO
  */

class ResultMethod{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //! Documentation TODO
  gnuplot GraphConvergence();


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //!Documentation TODO
  std::string NameMethod;
  //!Documentation TODO
  std::vector x_final;
  //!Documentation TODO
  std::vector<std::vector<std::double>> fvalue;

};

/* -------------------------------------------------------------------------- */
#endif //__RESULT_METHOD__HH__
