#include "StringWrapper.h"
#include <cstring>

StringWrapper::StringWrapper(){
    _str=new char [1];
    strcpy(_str,"");
}

StringWrapper::StringWrapper(const char *str){
    int a=strlen(str)+1;
    _str=new char [a];
    strcpy(_str, str);
}


StringWrapper::~StringWrapper(){
    if(_str!=nullptr)
        delete [] _str;
}


bool StringWrapper::operator==(const StringWrapper &str) const{
    return !strcmp(_str, str._str);
}


StringWrapper StringWrapper::operator+(const StringWrapper &str)const{
    int a=strlen(_str)+strlen(str._str)+1;
    char * string=new char[a];
     strcpy(string,_str);
     strcat(string,str._str);
     StringWrapper tmp(string);
     delete [] string;
     return tmp;
}



std::ostream & operator<<(std::ostream & output, const StringWrapper &str){
    return output<<str._str;
}


StringWrapper StringWrapper::operator*(int count)const{
    int size=count*strlen(_str)+1;
    char* string=new char[size];
    strcpy(string,_str);
    for(int i=1; i<count; i++){
        strcat(string,_str);
    }
    StringWrapper tmp(string);
    delete [] string;
    return tmp; 
}

StringWrapper operator*(const int count, const StringWrapper& str){
    return str.operator*(count);
}

StringWrapper & StringWrapper::operator=(const StringWrapper &str){
    if(this==&str) return *this;

    delete [] _str;

    int size=strlen(str._str)+1;
    _str=new char [size];
    strcpy(_str,str._str);
    return *this;
}



/*bool operator==(const StringWrapper &str1,const StringWrapper &str2){
    if(str1._str==str2._str) return true;
    else return false;
}*/
