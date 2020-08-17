#include "coin.h"
#include <iostream>

Coin::Coin(coin cop){
   value=cop;
   toss();
Side=get_side_up();
}
////////////////////////////
Coin::Coin(){
    value=one;
    toss();
    Side=get_side_up();
}
///////////////////////////
int Coin::get_coin_value(){
    return value;
}
////////////////////////////////
void Coin::print_side_up(){
    if(Side==heads)
        std::cout<<"heads"<<std::endl;
    else
    {
        std::cout<<"tails"<<std::endl;
    }
    
}
//////////////////////////////////////
side Coin::get_side_up(){
    
    return Side;
}
////////////////////////////////////////
void Coin::toss(){
        Side = side(rand()%2);
}
