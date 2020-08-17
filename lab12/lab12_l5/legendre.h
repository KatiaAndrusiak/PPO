#ifndef legendre_h
#define legendre_h
#include "polynomial.h"

class Legendre : public Polynomial{
public:
    Legendre(int n);
    Legendre(const Legendre & lnr): Polynomial(lnr){}
    Legendre(Legendre && lnr): Polynomial(lnr){}
    Legendre &operator=(const Legendre & lnr);
    Legendre &operator=(Legendre && lnr);

};

#endif
