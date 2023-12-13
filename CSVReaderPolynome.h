#ifndef GENERATEDFROMCODEGENERATOR_CSVREADERPOLYNOME_H
#define GENERATEDFROMCODEGENERATOR_CSVREADERPOLYNOME_H

#include "polynomial_1_to_n.hh"
#include <string>
using namespace std;

class CSVReaderPolynome{

    /* ------------------------------------------------------------------------ */
    /* Methods                                                                  */
    /* ------------------------------------------------------------------------ */

public:
    Polynomial1ToN Read(const std::string& NameFile);
};

#endif //GENERATEDFROMCODEGENERATOR_CSVREADERPOLYNOME_H
