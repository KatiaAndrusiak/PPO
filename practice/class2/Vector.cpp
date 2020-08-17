#include "Vector.h"
#include <iostream>

 Vector::Vector(int size, int value){
    Size=size;
    tab= new int [size];
    int i;
    for(i=0; i<size; i++){
       tab[i]=value;
    }
 }

 //////////////////////////////////////////
Vector::Vector(){}


 void Vector::print(){
     int i;
     for(i=0; i<Size ;i++){
         std::cout<<tab[i]<<" ";
     }
 }

 /////////////////////////////////////////////

 void Vector::mul(int a){
     int i;
     for(i=0; i<Size ;i++){
        tab[i] *=a;
     }
 }

//////////////////////////////////////////
Vector & Vector::add(const int value){
    for(int i = 0; i < Size; i++)
			tab[i] += value;
    return *this;
}

/////////////////////////
/*void Vector::add(Vector & vectorToAdd){
    for(int i = 0; i < Size; i++)
     tab[i] += vectorToAdd.at(i);
}
*/

//////////////////////////
int & Vector::at(const int c){
    return tab[c];
}