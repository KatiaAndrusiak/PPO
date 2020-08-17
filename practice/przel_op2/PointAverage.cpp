#include "PointAverage.h"
#include <iostream>

Point2D operator+(double a, const Point2D & point){
    Point2D tmp;
    tmp._x=a+point._x;
    tmp._y=a+point._y;
    return tmp;
}


Point2D Point2D::operator+(const Point2D &point){
    Point2D tmp;
    tmp._x=_x+point._x;
    tmp._y=_y+point._y;
    return tmp;
}

void Point2D::Print(){
    std::cout<<"Point2D:: ("<<_x<<","<<_y<<")"<<std::endl;
}

Point2D & Point2D::operator--(){
    --_x;
    --_y;
    return *this;
}

Point2D  Point2D::operator++(int){
    Point2D tmp(_x,_y);
    ++_x;
    ++_y;
    return tmp;
}


void * Point2D::operator new(size_t size){
    std::cout<<"Point2D:: alokowanie "<<size<<" bajtow"<<std::endl;
    return (new Point2D[size]);
}

PointAverage::PointAverage(){
    index=0;
    point._x=0;
    point._y=0;
}


void PointAverage::operator()(const Point2D &pnt){
    index++;
    point._x+=pnt._x;
    point._y+=pnt._y;
}



void PointAverage::Print(){
    std::cout<<"Average Point:: ("<<(point._x/index)<<","<<(point._y/index)<<")"<<std::endl;
}

void PointAverage::Reset(){
    index=0;
    point._x=0;
    point._y=0;
}

 void Point2D::operator delete(void* wsk){
     std::cout<<"Point2D:: zwalnianie wskaznika"<<std::endl;
     delete wsk;
 }

