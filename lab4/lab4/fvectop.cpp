#include<cmath>
#include "fvector.h"

///Funkcja ktora oblicza mase niezmiennicza
double InvariantMass(double *vect){
    double masa;
    double zm = vect[0] * vect[0] - vect[1] * vect[1] - vect[2] * vect[2] - vect[3] * vect[3];
    if (zm>=0){
        masa=sqrt(zm);
    }
    else{
        masa = -sqrt(abs(zm));
    }
    return masa;
}
///Funkcja ktora dodaje vectory
FourVector *AddFourVectors(FourVector vect1, FourVector vect2){
    FourVector *vect_s= new FourVector;
    vect_s->x=vect1.x + vect2.x;
    vect_s->y =vect1.y + vect2.y;
    vect_s->z=vect1.z + vect2.z;
    vect_s->t=vect1.t + vect2.t;
    vect_s->M=sqrt(vect_s->t*vect_s->t - vect_s->x*vect_s->x -vect_s->y*vect_s->y -vect_s->z*vect_s->z);
return vect_s;
}

///Funkcja ktora oblica scalar
double ScalarProduct(FourVector vect1, FourVector vect2){
    double scalar=0.0;
    scalar=vect1.t * vect2.t - vect1.x *vect1.x - vect1.y * vect2.y - vect1.z * vect2.z;
    return scalar;
}

