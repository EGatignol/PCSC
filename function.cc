#include "function.hh"
/* -------------------------------------------------------------------------- */

Function::Function(int dim_F, int dim_X){
    // Check that the dimensions are greater than 0.
    if ((dim_X == 0) || (dim_F==0)){
        throw std::invalid_argument("Function: The dimension of X and the dimension of F(X) need to be greater than 0.");
    }
    dimF = dim_F;
    dimX = dim_X;
}
