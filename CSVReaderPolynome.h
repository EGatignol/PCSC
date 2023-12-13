#ifndef GENERATEDFROMCODEGENERATOR_CSVREADERPOLYNOME_H
#define GENERATEDFROMCODEGENERATOR_CSVREADERPOLYNOME_H

#include "polynomial_1_to_n.hh"
#include <string>
using namespace std;

/**
  * Class to obtain a polynomial function (Polynomial1ToN) from a CSV-files
  * which contains the coefficients.
  */

class CSVReaderPolynome{

    /* ------------------------------------------------------------------------ */
    /* Methods                                                                  */
    /* ------------------------------------------------------------------------ */

public:
    /// Methode to gat the function from a CSV-file
    Polynomial1ToN Read(const std::string& NameFile);
};

#endif //GENERATEDFROMCODEGENERATOR_CSVREADERPOLYNOME_H
