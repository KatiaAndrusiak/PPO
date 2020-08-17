#include "coin.h"
#include "piggybank.h"
#include <iostream>

Piggybank::Piggybank(int rozm){
        size=rozm;
        tab=new Coin [rozm];
        ix=0;
        sum=0;
        
    }
 Piggybank::~Piggybank(){
     delete  tab;
 }

////////////////////////////////////////////////////////
void Piggybank::put_coin(Coin &pln){
    if(ix<size){
        tab[ix]=pln;
    ix++;
    }
    else
    {
        std::cout<<"Piggybank is full..."<<std::endl;
    }
    
}
////////////////////////////////////////////////////////////
int Piggybank::get_tot_value(){
    
    int i;
    
    for(i=0; i<ix; i++ ){
        sum+=tab[i].get_coin_value();
    }
    
    return sum;
}
