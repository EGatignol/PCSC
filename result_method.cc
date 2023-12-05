#include "result_method.hh"

ResultMethod::ResultMethod(std::string Name_method, Eigen::Matrix<double,-1,1> x, std::vector<Eigen::VectorXd> Value_f_by_iteration){
    NameMethod = Name_method;
    x_final = x;
    fvalue = Value_f_by_iteration;
}

/* -------------------------------------------------------------------------- */

gnuplot ResultMethod::GraphConvergence(){

}



/* --------------------------------------------------------------------------- */


