#include "mystring.h"
//#include <string.h>
#include <iostream>
#include <cmath>

MyString **str_tab= new MyString *[5];
int num=0;

const int N=5;
const int Z=13;


MyString * CreateString(const char *str){
    MyString *string= new MyString;
    if(str!=NULL){
    string->str=str;
    if(num<N){
        int i=0;
        do{ 
            i++;  
        }while((*string).str[i]!='\0');

        
        if(i+1<=Z){
            string->length=i+1; 
        }
        else
        {
            std::cout<<"CreateString: String is too long."<<std::endl;
            delete string;
            return nullptr;
        }
        

    }
    else{
        std::cout<<"CreateString: Maximum no of strings has been reached."<<std::endl;
        delete string;
            return nullptr;
    }
    str_tab[num]=string;
    num++;
    }
    else{
        std::cout<<"CreateString: NULL pointer passed. No object created."<<std::endl;
            return nullptr;   
    }

    return string;  

}

void PrintMyString(MyString *str){
    
   //const char *word=str->str;
   if(str!=NULL)
    std::cout <<str->str<< std::endl;
else{
    std::cout<<"PrintMyString: NULL pointer passed."<<std::endl;
}
}

///funkcja dla zwolnienia pamieci
void ClearStrings(void){
    for(int i=0; i<num; i++){
        delete str_tab[i];
}
}
