#ifndef Trojkat_h
#define Trojkat_h
#include "Ksztalt.h"
#include <cmath>

class Trojkat : public Ksztalt{
public:
    Trojkat(const int &a,const int &b, const int &c): _a(a), _b(b), _c(c) {}
    void wypisz(std::ostream& o) const;
    const double polePow() const;

private:
    int _a;
    int _b;
    int _c;
};

void Trojkat::wypisz(std::ostream& o) const{
   o << "Trojkat bokach:" << _a << " " << _b << " " << _c << std::endl;
}
const double Trojkat::polePow() const{
    double obw=0.5*(_a+_b+_c);
    return sqrt(obw*(obw-_a)*(obw-_b)*(obw-_c));
}

#endif
