#include "MyString.h"
#include <cstring>
#include <iostream>

MyString::MyString(const char *napis){
    int rozm;
    rozm = strlen(napis)+1;
    zmienna = new char [rozm];
    strcpy(zmienna,napis);
}

char* MyString::str(){
        return zmienna;
    }

 void MyString::join(const MyString &zm){
        int rozm;
        rozm=strlen(zmienna)+ strlen(zm.zmienna)+1;
        char *tmp = new char [rozm];
        strcpy(tmp, zmienna);
        strcat(tmp, zm.zmienna);

        delete [] zmienna;
        zmienna = tmp;
 }

 void MyString::replace(const char *str){
     int rozm;
     rozm=strlen(str)+1;
     char *tmp = new char[rozm];
     strcpy(tmp,str);
     delete [] zmienna;
     zmienna = tmp;
 }

 void swap (MyString &s1, MyString &s2){
     char * bufor = new char [strlen(s1.str())+1];
     strcpy(bufor,s1.str());
     s1.replace(s2.str());
     s2.replace(bufor);

     delete [] bufor;

 }
 MyString::~MyString(){
   std::cout<<"- deleting "<<zmienna<<std::endl;
   delete [] zmienna; 
 }
   