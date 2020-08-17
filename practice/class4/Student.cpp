#include "Student.h"
#include "StudentsList.h"
#include <iostream>
#include<cstring>

Student::Student(const char *name, const char *surname){
    int a=strlen(surname);
    _surname= new char [a+1];
    _surname=surname;
    int b=strlen(name);
    _name=new char [b+1];
    _name=name;
    

}

Student::Student(){
}



void Student::Print(){
    std::cout<<"Student ID: "<<_id<<", "<<" Name: "<<_name<<", "<<"Surname: "<<_surname<<std::endl;
}


