#ifndef library_h
#define library_h
#include <iostream>
#include"book.h"
using namespace std;
class Library{
Book** lib;
int akt;
int poj;
public:
Library(int n){
    lib = new Book*[n];
    akt=0;//aktualna pojemnosc
    poj=n;//pojemnosc
}


Library(const Library & libr){
    akt=libr.akt;
    poj=libr.poj;
    lib = new Book*[poj];
    for(int i=0; i<akt; i++){   //poprawione
        lib[i]=new Book(*libr.lib[i]); //poprawione
    }
}



Library(Library &&Libr){
    akt=Libr.akt;
    Libr.akt=0;
    poj=Libr.poj;
    Libr.poj=0;
    lib=Libr.lib;
    Libr.lib=nullptr;
}
~Library(){
    if(lib){
        for(int i=0; i<akt; i++){ //poprawione(zakres)
            delete lib[i];
        }
        delete [] lib;
    }
}
Book** get_books();
Book* get_book(string t);
void new_book(Book tmp);
unsigned int get_n_books(); //poprawione (dodalam unsigned)

};

#endif