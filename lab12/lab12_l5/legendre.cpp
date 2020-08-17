#include "legendre.h"
#include <cmath>
#include <utility>

    //Konstruktor jednoargumentowy obliczający współczynniki wielomianu Legendre'a
    Legendre::Legendre(int n) : Polynomial(n)
    {
        for(int i = n%2; i<=n; i+=2){
        _wsp[i] = (double)pow(-1, (n-i)/2) / (double)pow(2,n);
        _wsp[i] *= (double) std::tgamma(n+i+1);
        _wsp[i] /= (double) std::tgamma((n-i)/2 + 1);
        _wsp[i] /= (double) std::tgamma((n+i)/2 + 1);
        _wsp[i] /= (double) std::tgamma(i + 1);
        }
    }

    //Operator przypisania kopiującego
    Legendre & Legendre::operator=(const Legendre & lnr)
    {
        (*this).Polynomial::operator=(lnr);
        return *this;
    }

    //Operator przypisania przenoszacego
    Legendre & Legendre::operator=(Legendre && lnr)
    {
        (*this).Polynomial::operator=(std::move(lnr));
        return *this;
    }