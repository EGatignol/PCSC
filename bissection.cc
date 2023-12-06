#include "bissection.hh"
#include <stdexcept>

Bissection::Bissection(std::pair<double,double> inter_init, const double tol, const int max_iter): FindRoot(tol, max_iter){
    Interval = inter_init;
}
/* -------------------------------------------------------------------------- */

ResultMethod Bissection::MethodFindRoot(Function &F){
    std::string Name = "Bissection";

    // Check that the function is from R to R
    if (F.dimX != 1 || F.dimF != 1){
        throw std::invalid_argument("Bissection: The function is not from R to R.") ;
    }
    // Check that the interval [a,b] is s.t. a<b
    Eigen::VectorXd a,b ;
    a[0] = Interval.first;
    b[0] = Interval.second;
    if (a[0] >= b[0]){
        throw std::invalid_argument("Bissection: The initial interval [a,b] is invalid sinc a>=b.");
    }
    // Check that f(a)*f(b) <= 0
    Eigen::VectorXd f_a = F.Func(a);
    Eigen::VectorXd f_b = F.Func(b);
    if (f_a[0]*f_b[0] > 0){
        throw std::invalid_argument("Bissection: Interval need to have a value s.t f(x) < 0 and one s.t. f(x)>0.");
    }

    std::vector<Eigen::VectorXd> f_values;
    f_values.reserve(MaxIter);

    if (f_a = 0){
        f_values.push_back(f_a);
        ResultMethod Results(Name, a, f_values);
        return Results;
    }
    if (f_b = 0){
        f_values.push_back(f_b);
        ResultMethod Results(Name, b, f_values);
        return Results;
    }

    Eigen::VectorXd m;
    Eigen::VectorXd f_m;
    for (int iter=0; iter<MaxIter; iter++ ){
        m = (a+b)/2;
        f_m = F.Func(m);
        f_values.push_back(f_m);
        if (f_m = 0){
            ResultMethod Results(Name, m, f_values);
            return Results;
        }
        if (f_a[0][0]*f_m[0][0] < 0){
            b = m;
        }
        if (f_b[0][0]*f_m[0][0] < 0){
            a = m;
        }
        if (abs(a[0]-b[0]) < tolerance){
            ResultMethod Results(Name, m, f_values);
            return Results;
        }
    }
    ResultMethod Results(Name, m, f_values);
    return Results;
}



/* --------------------------------------------------------------------------- */


