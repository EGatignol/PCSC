#include "result_method.hh"

ResultMethod::ResultMethod(std::string Name_method, vector<double> x, std::vector<std::vector<double>> Value_f_by_iteration){
    NameMethod = Name_method;
    x_final = x;
    fvalue = Value_f_by_iteration;
}

/* -------------------------------------------------------------------------- */

gnuplot ResultMethod::GraphConvergence(){

}



/* --------------------------------------------------------------------------- */


