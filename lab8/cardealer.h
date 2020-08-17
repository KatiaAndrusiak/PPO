#ifndef cardealer_h
#define cardealer_h
#include "car.h"
class SubaruDealer{
public:
    SubaruDealer(int max);
    ~SubaruDealer();
    void new_inventory(const SubaruCar &new_car, int numint, int cena);
    SubaruCar* show(int num);
    void sell(int numint);
    int get_income();
    static int get_all_dealers_income();
private:
    static int n;
    int max_rozm;
    SubaruCar *car;
    int zarobek;
    int i;
};

#endif