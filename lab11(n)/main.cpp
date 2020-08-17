#include <iostream>
#include "kwaternion.h"


template <class Type> Type  mkcopy(Type obj) {
	return obj; }

int main()
{
    std::cout<<"Obiekt 1\n";
    Quaternion a;
    std::cout<<a<<std::endl;

    std::cout<<"Obiekt 2\n";
    Quaternion b(1, 2, 3, 4);
    std::cout<<b<<std::endl;

    std::cout<<"Obiekt 3\n";
    Quaternion c(b);
    std::cout<<c<<std::endl;


    std::cout<<"Obiekt 4\n";
    Quaternion d = mkcopy(c);
    std::cout<<d<<std::endl;

    std::cout<<"Obiekt 5\n";
    Quaternion e;
    e = d;
    std::cout<<e<<std::endl;

    std::cout<<"Obiekt 6\n";
    Quaternion f;
    f = Quaternion (1,1,1,1);
    std::cout<<f<<std::endl;

    std::cout<<"Obiekt 7\n";
    Quaternion g;
    g = f + e;
    std::cout<<g<<std::endl;
 
    std::cout<<"Obiekt h\n";
    Quaternion h = g * g;
    std::cout<<h<<std::endl;

     std::cout<<-h<<std::endl;

     for (int i=0; i<3; i++){
        std::cout<<h[i]<<std::endl;
    }

    std::cout<<2*h<<std::endl;
    std::cout<<h*2<<std::endl;/**/


    return 0;
}
