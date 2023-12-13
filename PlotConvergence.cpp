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
    gp << "plot '-' with linespoints title 'Convergence of the method'\n";
    gp.send1d(vnorm);
}