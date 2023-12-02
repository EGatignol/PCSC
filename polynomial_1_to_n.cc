#include "polynomial_1_to_n.hh"

Polynomial1ToN::Polynomial1ToN(std::vector<std::vector<double>> coeffs, const int dim_F, const int dim_X): Function(dim_F,dim_X){
    coefficients = coeffs;
}
/* -------------------------------------------------------------------------- */

Eigen::Matrix<double, -1, 1> Polynomial1ToN::Func(std::vector<double> X) {

}



/* --------------------------------------------------------------------------- */

Eigen::Matrix<double, -1, -1> Polynomial1ToN::DerivedFunc(std::vector<double> X){

}



/* --------------------------------------------------------------------------- */


