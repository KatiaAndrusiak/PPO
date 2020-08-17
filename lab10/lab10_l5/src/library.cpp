
#include <iostream>
#include "library.h"
#include "book.h"
using namespace std;



Book** Library::get_books(){
    return lib;
}


Book* Library::get_book(string t){
    for(int i=0; i<akt; i++){
      if(lib[i]->tytul == t){ //poprawione(szukamy po tytule)
        return lib[i];
        }
    }
    return nullptr; //poprawione (dodalam)
    cout<<"Looking for book: "<<t<<" ...   not found."<<endl;
}
void Library::new_book(Book tmp){
    if(akt>=poj){
     cout<<"not space"<<endl;
      }
      else{
        lib[akt]=new Book(tmp);
        akt++;
      }
}
unsigned int Library::get_n_books(){ //poprawione
    return akt;
}