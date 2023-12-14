#include "PlotConvergence.h"
#include "gnuplot-iostream.h"

void PlotConvergence::getGraphConv(ResultMethod &r){
    //creates a vector containing the norm of the evaluate function at each step
    std::vector <double> vnorm;
    vnorm.reserve(r.fvalue.size()); //reserve space

    //range loop over all element of fvalue
    for (auto& v : r.fvalue){
        double norm = v.norm();
        vnorm.push_back(norm);
    }

    //creating graph using gnuplot
    Gnuplot gp;
    gp << "set xlabel 'number of iterations' font ',5'\n";
    gp << "set ylabel 'norm of the evaluate function' font ',5'\n";
    gp << "set tics font ',3'\n";
    gp << "set key font ',3'\n";
    gp << "plot '-' with linespoints title '"<< r.NameMethod<<"'\n";
    gp.send1d(vnorm);
}