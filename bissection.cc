#include "bissection.hh"
#include <stdexcept>

Bissection::Bissection(std::pair<double,double> inter_init, const double tol, const int max_iter): FindRoot(tol, max_iter){
    Interval = inter_init;
}
/* -------------------------------------------------------------------------- */

std::string Bissection::getName(){
    return "Bisection";
}

ResultMethod Bissection::MethodFindRoot(Function &F){

    // Check that the function is from R to R
    if (F.dimX != 1 || F.dimF != 1){
        throw std::invalid_argument("Bisection: The function is not from R to R.") ;
    }
    // Check that the interval [a,b] is s.t. a<b
    Eigen::VectorXd a(F.dimX),b(F.dimX) ;
    a[0] = Interval.first;
    b[0] = Interval.second;
    if (a[0] >= b[0]){
        throw std::invalid_argument("Bisection: The initial interval [a,b] is invalid since a>=b.");
    }
    // Check that f(a)*f(b) <= 0
    auto f_a = F.Func(a);
    auto f_b = F.Func(b);
    if (f_a[0]*f_b[0] > 0){
        throw std::invalid_argument("Bisection: Interval need to have a value s.t f(x) < 0 and one s.t. f(x)>0.");
    }

    // Create the vector, which will save the values of f during the iteration.
    std::vector<Eigen::VectorXd> f_values;
    f_values.reserve(MaxIter);

    // Check if a or b is a root of the function.
    auto VectZero = Eigen::VectorXd::Zero(f_a.size());
    if (f_a == VectZero){
        f_values.push_back(f_a);
        ResultMethod Results(getName(), a, f_values);
        return Results;
    }
    if (f_b == VectZero){
        f_values.push_back(f_b);
        ResultMethod Results(getName(), b, f_values);
        return Results;
    }

    // Bisection method:
    Eigen::VectorXd m(F.dimX);
    Eigen::VectorXd f_m(F.dimF);
    for (int iter=0; iter<MaxIter; iter++ ){
        m = (a+b)/2;
        f_m = F.Func(m);
        f_values.push_back(f_m);
        // Check if m is a root of the function
        if (f_m == VectZero){
            ResultMethod Results(getName(), m, f_values);
            return Results;
        }
        // Change the interval according to the value of f(m).
        if (f_a[0]*f_m[0] < 0){
            b = m;
        }
        if (f_b[0]*f_m[0] < 0){
            a = m;
        }
        // Check that the length of the interval is greater than the tolerance.
        if (abs(a[0]-b[0]) < tolerance){
            ResultMethod Results(getName(), m, f_values);
            return Results;
        }
    }
    ResultMethod Results(getName(), m, f_values);
    return Results;
}



/* --------------------------------------------------------------------------- */


