#include <iostream>
#include "cardealer.h"
#include "car.h"
int SubaruDealer::n;
    //konstruktor kopijujacy
    SubaruDealer::SubaruDealer(int max){
        i=0;
        zarobek=0;
        max_rozm=max;
        car= new SubaruCar [max_rozm];
    }
    
    //dodaje autka do salonu
    void SubaruDealer::new_inventory(const SubaruCar &new_car, int numint, int cena){
        if(i<max_rozm){
        car[i].nazwa=new_car.nazwa;
        car[i].rok=new_car.rok;
        car[i].przebieg=new_car.przebieg;
        car[i].numer=numint;
        car[i].cena=cena;
        i++;
        }
        else{
            std::cout<<"SubaruDealer: No place for more cars."<<std:: endl;
            return;
        }

    }

    //funkcja ktora zwraca autko z podanym numerem
    SubaruCar* SubaruDealer::show(int num){
        int j=0;
        while(j<i){
            if(car[j].numer==num){
                return &car[j];
            }
            j++;
        }
       return nullptr; 
    }


    //funkcja ktora sprzedaje autka z salonu
    void SubaruDealer::sell(int numint){
        SubaruCar *autko=show(numint);
        if(autko!=nullptr){
        zarobek+=autko->cena;
        n+=autko->cena;
        autko->nazwa="noname";
        autko->numer=0;
        autko->przebieg=0;
        autko->rok=0;
        autko->cena=0;
        }
        else {
            std::cout<<"SubaruDealer: no such car."<<std::endl;
        }


    }


    int SubaruDealer::get_income(){
        return zarobek;
    }

    int SubaruDealer::get_all_dealers_income(){
        return n; ///nie zdazylam
    }


   SubaruDealer:: ~SubaruDealer(){
       delete [] car;
   }


