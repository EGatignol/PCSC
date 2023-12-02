#include "bissection.hh"
#include <stdexcept>

Bissection::Bissection(std::pair<double,double> inter_init): FindRoot(){
    Interval = inter_init;
}
Bissection::Bissection(std::pair<double,double> inter_init, const double tol, const int max_iter, const double epsil): FindRoot(tol, max_iter, epsil){
    Interval = inter_init;
}
/* -------------------------------------------------------------------------- */

ResultMethod Bissection::MethodFindRoot(Function F){
    std::string Name = "Bissection";

    // Check that the function is from R to R
    if (F.dimX != 1 || F.dimF != 1){
        throw std::invalid_argument("Bissection: The function id not from R to R.") ;
    }
    // Check that the interval [a,b] is s.t. a<b
    std::vector<double> a,b ;
    a[0] = Interval.first;
    b[0] = Interval.second;
    if (a >= b){
        throw std::invalid_argument("Bissection: The initial interval [a,b] is invalid sinc a>=b.");
    }
    // Check that f(a)*f(b) <= 0
    Eigen::Matrix<double,1,1> f_a = F.Func(a[0]);
    Eigen::Matrix<double,1,1> f_b = F.Func(b[0]);
    if (f_a[0][0]*f_b[0][0] > 0){
        throw std::invalid_argument("Bissection: Interval need to have a value s.t f(x) < 0 and one s.t. f(x)>0.");
    }

    std::vector<std::vector<double>> f_values;

    if (f_a[0][0] == 0){
        f_values[0][0] = f_a[0][0];
        ResultMethod Results(Name, a, f_values);
        return Results;
    }
    if (f_b[0][0] == 0){
        f_values[0][0] = f_b[0][0];
        ResultMethod Results(Name, b, f_values);
        return Results;
    }

    vector<double> m;
    Eigen:: Matrix<double,1,1> f_m;
    for (int iter=0, iter<MaxIter, iter++ ){
        m[0] = (a[0]+b[0])/2;
        f_m[0][0] = F.Func(m);
        f_values[0][iter] = f_m[0][0];
        if (f_m[0][0] == 0){
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


