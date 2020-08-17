#ifndef fvector_h
#define fvector_h

typedef struct Vector{
    double x;
    double y;
    double z;
    double t;
    double M;
} FourVector;

FourVector  *CreateFourVector(double *vect);
void PrintFourVector(FourVector vect);
void PrintFourVector(FourVector *vect);
void DeleteFourVector(FourVector *vect);


 
#endif