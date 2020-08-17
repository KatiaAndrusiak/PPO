#include "car.h"
#include <iostream>

    //konstor kopijujacy
    SubaruCar::SubaruCar(std::string nazw, int rokp, int przeb){
        nazwa=nazw;
        rok=rokp;
        przebieg=przeb;
    }


    SubaruCar::SubaruCar(){
        nazwa="noname";
        rok=0;
        przebieg=0;
        cena=0;
        numer=0;
    }


    std::string SubaruCar::get_model(){
        return nazwa;
    }


    int SubaruCar::get_year(){
        return rok;
    }


    int SubaruCar::get_mileage(){
        return przebieg;
    }

    

