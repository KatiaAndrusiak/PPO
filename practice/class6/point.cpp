#include "point.h"
#include <cstring>
#include <string>
#include <iostream>

Point::Point(){
    _name=nullptr;
    _x=0;
    _y=0;
    std::cout<<"konstruktor domyslny"<<std::endl;
}

Point::Point(double x, double y){
    _name= new char[17];
    strcpy(_name, "Miejsce nieznane");
    _x=x;
    _y=y;
    std::cout<<"konstruktor _x,_y"<<std::endl;

}

Point::Point(const char *name, double x, double y){
    int a=strlen(name)+1;
    _name=new char [a];
    strcpy(_name, name);
    _x=x;
    _y=y;
   std::cout<<"konstruktor dla wszystk"<<std::endl;

}


Point::Point(const Point& point){
    _x=point._x;
    _y=point._y;
    int a=strlen(point._name)+1;
    _name=new char[a];
    strcpy(_name, point._name);
    std::cout<<"konstruktor kopi"<<std::endl;

}


Point::Point(Point &&point){
    _x=point._x;
    point._x=0;
    _y=point._y;
    point._y=0;
    _name=point._name;
    point._name=nullptr;
     std::cout<<"konstruktor przen"<<std::endl;

}

Point::~Point(){
    delete [] _name;
}


void Point::fullPrint(){
    if(_name==nullptr)   std::cout<<"NULL"<<"("<<_x<<", "<<_y<<")"<<std::endl;
    else std::cout<<_name<<"("<<_x<<", "<<_y<<")"<<std::endl;
}


void Point::changeName(const char* name){
    delete [] _name;
    int a=strlen(name)+1;
    _name=new char [a];
    strcpy(_name, name);
}


void Point::move(double x, double y){
    _x=x;
    _y=y;
}

int compareX(const Point &a, const Point &b){
    if(a._x<b._x) return 1;
    else if (a._x==b._x) return 0;
    else return -1;
    
}

int compareY(const Point &a, const Point &b){
      if(a._y<b._y) return 1;
    else if (a._y==b._y) return 0;
    else return -1;
}

int compareXY(const Point &a, const Point &b){
    return 10*compareX(a,b)+compareY(a,b);
}


void directions(const Point &a, const Point &b, std::string cmp){
    if(cmp == "compareY"){
        switch(compareY(a,b))
        {
            case 1:
                 std::cout<<a._name<<" jest na poluden od "<<b._name<<std::endl;  
                 break;
            case -1:
                 std::cout<<a._name<<" jest na polnoc od "<<b._name<<std::endl;   
                 break;
            case 0:
                std::cout<<a._name<<" jest na tej samej długości co "<<b._name<<std::endl;   
                break;
            default:
                break;
        }
    }

       if(cmp == "compareX"){
        switch(compareX(a,b))
        {
            case 1:
                 std::cout<<a._name<<" jest na zachod od "<<b._name<<std::endl;  
                 break;
            case -1:
                 std::cout<<a._name<<" jest na wchod od "<<b._name<<std::endl;   
                 break;
            case 0:
                std::cout<<a._name<<" jest na tej samej długości co "<<b._name<<std::endl;   
                break;
            default:
                break;
        }
    }
    if(cmp == "compareXY"){
        switch(compareXY(a,b))
        {
            case 9:
                 std::cout<<a._name<<" jest na północny-zachód od "<<b._name<<std::endl;  
                 break;
            case -9:
                 std::cout<<a._name<<" jest na południowy-wschód od "<<b._name<<std::endl;   
                 break;
            case -11:
                std::cout<<a._name<<" jest na północny-wschód od "<<b._name<<std::endl;   
                break;
            case 11:
                std::cout<<a._name<<" jest na południowy-zachód od "<<b._name<<std::endl;   
                break;
            case 1:
                std::cout<<a._name<<" jest na tej samej długości co "<<b._name<<std::endl; 
                std::cout<<a._name<<" jest na poluden od "<<b._name<<std::endl; 
                break;
            case -1:
                std::cout<<a._name<<" jest na tej samej długości co "<<b._name<<std::endl;
                std::cout<<a._name<<" jest na polnoc od "<<b._name<<std::endl;     
                break;
            case 10:
                  std::cout<<a._name<<" jest na zachod od "<<b._name<<std::endl;
                  std::cout<<a._name<<" jest na tej samej długości co "<<b._name<<std::endl;      
                break;
            case -10:
                 std::cout<<a._name<<" jest na wchod od "<<b._name<<std::endl;   
                 std::cout<<a._name<<" jest na tej samej długości co "<<b._name<<std::endl;   
                break;
            
            default:
                break;
        }
    }
}













