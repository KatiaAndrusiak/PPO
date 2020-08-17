#ifndef bullet_h
#define bullet_h

#include <iostream>

class Bullet{
public:
    ~Bullet(){
      
    }
    Bullet(double caliber){
        _caliber=caliber;
        click();
    }
    Bullet(){
        get_caliber();
    }
  
    void click() { std::cout << "-click- "; }
    double get_caliber(){  return _caliber; }

private:
    double _caliber;
};


#endif