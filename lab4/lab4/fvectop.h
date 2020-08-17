#ifndef fvectop_h
#define fvectop_h
#include "fvector.h"

FourVector *AddFourVectors(FourVector vect1, FourVector vect2);
double ScalarProduct(FourVector vect1, FourVector vect2);
double InvariantMass(double *vect);

#endif