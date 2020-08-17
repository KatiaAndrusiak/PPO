#ifndef polynomial_h
#define polynomial_h
#include<iostream>


class Polynomial{
public:
    Polynomial(int count, double *wsp);
    Polynomial(int count);
    Polynomial(const Polynomial & pol);
    Polynomial(Polynomial && pol);
    Polynomial & operator=(const Polynomial &pol);
    Polynomial & operator=(Polynomial &&pol);
    ~Polynomial();
    Polynomial & operator+=(const Polynomial& pol);
    double operator()(double x);

    friend Polynomial operator*(const Polynomial & pol,const double k);
    friend std::ostream & operator<<(std::ostream & out, const Polynomial & pol);

protected:
    double *_wsp;
    int _count;
};


#endif