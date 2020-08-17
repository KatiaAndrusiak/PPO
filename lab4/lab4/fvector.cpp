#include<iostream>
#include "fvector.h"
#include "fvectop.h"
///Funkcja tworzaca vector
FourVector  *CreateFourVector(double *vect){
    FourVector  *nvect= new FourVector;
        nvect->x=vect[1];
        nvect->y=vect[2];
        nvect->z=vect[3];
        nvect->t=vect[0];
        nvect->M=InvariantMass(vect);
    return nvect;
}

///Funkcja ktora wypisuje vector
void PrintFourVector(FourVector vect){
        std::cout<<"("<< vect.t<<","<<vect.x<<","<<vect.y<<","<<vect.z<<")"<<std::endl;

}

void PrintFourVector(FourVector *vect){
    std::cout<<"("<< (*vect).t<<","<<(*vect).x<<","<<(*vect).y<<","<<(*vect).z<<")"<<std::endl;    
}


///Funkcja usuwajaca vektor
void DeleteFourVector(FourVector *vect){
    if(vect!=NULL){
        delete vect;
    }
}
