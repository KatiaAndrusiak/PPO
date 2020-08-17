#ifndef gun_h
#define gun_h
#include "bullet.h"

class Gun {
public:
    Gun(int N, double caliber);
    Gun(const Gun & gun);
    Gun(Gun &&gun);
    ~Gun();
    void load();
    void bang() { std::cout << "\nBang!" << std::endl;}
    void pull_trigger();
    void pull_trigger(int n);
    void mag_empty() { std::cout << "Gun: Magazine empty." << std::endl; }
    void chamb_empty() { std::cout << "Gun: Chamber is empty. Reload." << std::endl; }
    void new_magazine();

private:
    int _N;
    int _i;
    double _caliber;
 
    Bullet **tab;
    Bullet *komora;

};

#endif