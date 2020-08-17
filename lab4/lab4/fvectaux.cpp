#include "fvector.h"

///Fukcja zwalniajaca pamiec
void RemoveAllFourVectors(FourVector **fvectors,int rozm){
    for(int i=0; i<rozm; i++){
        delete fvectors[i] ;
    }
    delete [] fvectors;
}
