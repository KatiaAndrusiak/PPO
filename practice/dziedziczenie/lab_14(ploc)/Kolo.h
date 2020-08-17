#ifndef Kolo_h
#define Kolo_h
#include "Ksztalt.h"
#include <iostream>

class Kolo : public Ksztalt{
public:
    Kolo(const int& r): _r(r){}
    void wypisz(std::ostream& o) const;
    const double polePow() const override  ;

private:
    int _r;
};

void Kolo::wypisz(std::ostream& o) const{
    o<<"Kolo o promieniu:"<<_r<<std::endl;
 }

 const double Kolo::polePow() const{
     return 3.1415*_r*_r;
 }
#endif
