#ifndef car_h
#define car_h
#include <iostream>
class SubaruCar{
public:
    SubaruCar(std::string nazw, int rokp, int przeb);
    SubaruCar();
    friend class SubaruDealer;
    std::string get_model();
    int get_year();
    int get_mileage();

private:
    std::string nazwa;
    int rok;
    int przebieg;
    int numer;
    int cena;
};

#endif