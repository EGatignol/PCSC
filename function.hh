#ifndef __FUNCTION__HH__
#define __FUNCTION__HH__

/* -------------------------------------------------------------------------- */

/**
  * Documentation TODO
  */

class Function{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //! Documentation TODO
  virtual Eigen::Matrix<double, -1, 1> Func(std::vector<double> X)=0;
  //! Documentation TODO
  virtual Eigen::Matrix<double, -1, -1> DerivedFunc(std::vector<double> X)=0;


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //!Documentation TODO
  int dimX;
  //!Documentation TODO
  int dimF;

};

/* -------------------------------------------------------------------------- */
#endif //__FUNCTION__HH__
