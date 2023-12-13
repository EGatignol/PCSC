#include "PlotConvergence.h"
#include "gnuplot-iostream.h"

void PlotConvergence::getGraphConv(ResultMethod &r){
    std::vector <double> vnorm;
    vnorm.reserve(r.fvalue.size());

    for (const auto& v : r.fvalue){
        double norm = v.norm();
        vnorm.push_back(norm);
    }

    Gnuplot gp;
    gp << "set xlabel 'number of iterations' font ',5'\n";
    gp << "set ylabel 'norm of the evaluate function' font ',5'\n";
    gp << "set tics font ',3'\n";
    gp << "set key font ',3'\n";
    gp << "plot '-' with linespoints title '"<< r.NameMethod<<"'\n";
    gp.send1d(vnorm);
}