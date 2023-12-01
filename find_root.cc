#include "find_root.hh"
/* -------------------------------------------------------------------------- */

FindRoot::FindRoot(const double tol,const int maxit){
    MaxIter=maxit;
    tolerance= tol;
}
FindRoot::FindRoot(){
    MaxIter=1000;
    tolerance=10e-6;
}

