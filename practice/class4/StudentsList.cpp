#include "StudentsList.h"
#include "Student.h"
#include <cstring>
#include <iostream>

int StudentsList::_num;
StudentsList::StudentsList(const char *info){
    int a=strlen(info);
    _info=new char [a+1];
    _info=info;
    lista=new Student;
    lista->_next=nullptr;
    first=lista;
    _num++;
    lista->_id=_num;
}
//////////////////////////////////////////////
StudentsList::StudentsList(){
    lista=new Student;
    lista->_next=nullptr;
}
/////////////////////////////////

StudentsList::~StudentsList(){
    
    }

//////////////////////////////////////////////
void StudentsList::PrintInfo(){
    std::cout<<"[StudentsList]: "<<_info<<std::endl;
}

///////////////////////////////////////////
 void StudentsList::AddStudent( Student *student){
    Student *list = student;
    lista->_next=list;
    list->_next=nullptr;
    lista=list;
    
    
 }

 /////////////
void StudentsList::PrintList(){
    std::cout<<"[StudentsList]: "<<_info<<std::endl;
    //Student *tmp=first;
    while(first->_next!=nullptr){
        std::cout<<"Student ID: "<<first->_id<<", "<<" Name: "<<first->_name<<", "<<"Surname: "<<first->_surname<<std::endl;
    }
    
}


