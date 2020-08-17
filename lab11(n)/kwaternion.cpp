#include "kwaternion.h"

Quaternion::Quaternion(){
    _s=0;
    _V= new double [3]{0,0,0};
}


Quaternion::Quaternion(double s, double x, double y, double z){
    _s=s;
    _V=new double[3]{x,y,z};
}


Quaternion::Quaternion(const Quaternion &q){
    _s=q._s;
    _V=new double[3]{q._V[0], q._V[1], q._V[2]};
    std::cout<<"KK****"<<std::endl;
}

Quaternion::Quaternion(Quaternion &&q){
    _s=std::move(q._s);
    q._s=0;
    _V=std::move(q._V);
    q._V = nullptr;
    std::cout<<"KP****"<<std::endl;
}

Quaternion::~Quaternion(){
    if(_V!=nullptr)
        delete [] _V;
}




Quaternion & Quaternion::operator=(const Quaternion &q){
    if(this==&q) return *this;
    std::cout<<"OPK***\n";
    delete [] _V;

    _s=q._s;
    _V=new double[3]{q._V[0], q._V[1], q._V[2]};
    return *this;
}


Quaternion & Quaternion::operator=(Quaternion &&q){
   /*  _s = std::exchange (q._s, 0);
                std::swap (_V, q._V); */
std::cout<<"OPP***\n";
    _s=std::move(q._s);
    q._s=0;
    delete [] _V;
    _V=std::move(q._V);
    q._V = nullptr;
            return *this;
}




Quaternion & Quaternion::operator+(const Quaternion &q){
    _s+=q._s;
    for(int i=0; i<3; i++){
        _V[i]+=q._V[i];
    }
    return *this;
}



Quaternion  operator*(const Quaternion &q1, const Quaternion &q2){
     Quaternion tmp;
     double s=q1._s*q2._s-q1._V[0]*q2._V[0]-q1._V[1]*q2._V[1]-q1._V[2]*q2._V[2];
     double x=q1._s*q2._V[0]+q1._V[0]*q2._s+q1._V[1]*q2._V[2]-q1._V[2]*q2._V[1];
     double y=q1._s*q2._V[1]-q1._V[0]*q2._V[2]+q1._V[1]*q1._s+q1._V[2]*q2._V[0];
     double z=q1._s*q2._V[2]+q1._V[0]*q2._V[1]-q1._V[1]*q2._V[0]+q1._V[2]*q2._s;
    tmp._s=s;
    tmp._V[0]=x;
    tmp._V[1]=y;
    tmp._V[2]=z;
    return tmp;
     //q1*q2 = a1*a2-x1*x2-y1*y2-z1*z2 + i*(a1*x2+x1*a2+y1*z2-z1*y2) + j*(a1*y2-x1*z2+y1*a2+z1*x2) + k*(a1*z2+x1*y2-y1*x2+z1*a2)
 }

  Quaternion   Quaternion::operator-(){
      Quaternion tmp;
        tmp._s = _s;
        for(int i = 0; i < 3; i++){
            tmp._V[i] = -_V[i];
        }
        return tmp;
   }

   Quaternion Quaternion::operator*(const double a){
    Quaternion tmp(a*_s, a*_V[0], a*_V[1], a*_V[2]);
    return tmp;
   }



Quaternion operator*(const double a, const Quaternion &zm){
    Quaternion tmp(a*zm._s, a*zm._V[0], a*zm._V[1], a*zm._V[2]);
    return tmp;
}



std::ostream& operator<< (std::ostream &output, const Quaternion &q){
    output<<"Quaternion q = "<<q._s<<" + i"<<q._V[0]<<" + j"<<q._V[1]<<" + k"<<q._V[2]<<"\n";
    return output;
}
