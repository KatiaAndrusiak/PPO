#ifndef kwaternion_h
#define kwaternion_h
#include<iostream>
#include <utility>

class Quaternion{
public:
    Quaternion();
    Quaternion(double s, double x, double y, double z);
    Quaternion(const Quaternion &q);
    Quaternion(Quaternion&& q);
    ~Quaternion();
    Quaternion & operator=(const Quaternion &q);
    Quaternion & operator=(Quaternion &&q);
    Quaternion & operator+(const Quaternion &q);
    Quaternion  operator-();
    const double &operator[](unsigned i){
        return _V[i];} 
    Quaternion operator*(const double a);
   // Quaternion & operator*(const Quaternion &q);
    friend std::ostream& operator<<(std::ostream &output, const Quaternion &q);
    friend Quaternion  operator*(const Quaternion &q1, const Quaternion &q2);
    friend Quaternion operator*(const double a, const Quaternion &zm);

private:
    double _s;
    double *_V;
};

std::ostream& operator<< (std::ostream &output, const Quaternion &q);
Quaternion operator*(const double a, const Quaternion &zm);
 Quaternion  operator*(const Quaternion &q1, const Quaternion &q2);


#endif