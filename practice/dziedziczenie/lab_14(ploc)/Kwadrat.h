#ifndef Kwadrat_h
#define Kwadrat_h
#include "Ksztalt.h"
#include <iostream>
class Kwadrat : public Ksztalt{
public:
    Kwadrat(const int &a): _a(a){}
    void wypisz(std::ostream& o) const;
    const double polePow() const;

private:
    int _a;
};

void Kwadrat::wypisz(std::ostream& o) const{
    o<<"Kwadrat o boku:"<<_a<<std::endl;
}
const double Kwadrat::polePow() const{
    return _a*_a;
}
#endif
