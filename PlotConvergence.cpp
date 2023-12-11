#include "PlotConvergence.h"
#include "gnuplot-iostream/gnuplot-iostream.h"

void PlotConvergence::getGraphConv(){
    std::vector <double> vnorm;
    vnorm.reserve(fvalue.size());

    for (const auto& v : fvalue){
        double norm = v.norm();
        vnorm.push_back(norm);
    }

    Gnuplot gp;
    gp << "plot '-' with linespoints title 'Convergence of the method'\n";
    gp.send1d(vnorm);
}