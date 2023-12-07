#include "polynomial_1_to_n.hh"

Polynomial1ToN::Polynomial1ToN(std::vector<vector<double>> coeffs, int dim_F, int dim_X): Function(dim_F,dim_X){
    coefficients = coeffs;
}
/* -------------------------------------------------------------------------- */

Eigen::VectorXd Polynomial1ToN::Func(Eigen::VectorXd X) {
    Eigen::VectorXd values_f(dimF);
    for (int f_i=0; f_i<=dimF-1; f_i++) {
        values_f[f_i]=0; // Optimal ça?
        int max_pow_fi = coefficients[f_i].size();
        for (int pow_i=0; pow_i<=max_pow_fi-1; pow_i++ ){
            values_f[f_i]=values_f[f_i] + coefficients[f_i][pow_i]*pow(X[0],pow_i);
        }
    }
    return values_f;
}



/* --------------------------------------------------------------------------- */

Eigen::Matrix<double, -1, -1> Polynomial1ToN::DerivedFunc(Eigen::VectorXd X){
    Eigen::Matrix<double, -1, 1> values_f(dimF);
    for (int f_i=0; f_i<=dimF-1; f_i++) {
        values_f[f_i]=0;
        int max_pow_fi = coefficients[f_i].size();
        for (int pow_i=1; pow_i<=max_pow_fi-1; pow_i++) {
            values_f[f_i]=values_f[f_i] + coefficients[f_i][pow_i]*pow_i*pow(X[0],pow_i-1);
        }
    }
    return values_f;

}



/* --------------------------------------------------------------------------- */


