#include "book.h"
///Andrusiak 
///Drwal(library)


///Konstruktor domyslny klasy Book
Book::Book(){
     tytul="nie znany";
     autor="nie znany";
     rok=0;
     gatunek=undefined;
     ISBN=0;
  }
///Konstruktor ktory ustawia dane
Book::Book(std::string tytul_, std::string autor_,short unsigned rok_, Genre gatunek_,    long unsigned ISBN_) {
     tytul=tytul_;
     autor=autor_;
     rok=rok_;
     gatunek=gatunek_;
     ISBN=ISBN_;
 }
 ///Konstruktor kopijujacy klasy Book
  Book::Book(const Book& book){
    tytul=book.tytul;
     autor=book.autor;
     rok=book.rok;
     gatunek=book.gatunek;
     ISBN=book.ISBN;
  }
///Konstruktor przenoszacy 
   Book::Book( Book&& book){
     tytul=std::move(book.tytul);
     autor=std::move(book.autor);
     rok=book.rok;
     gatunek=book.gatunek;
     ISBN=book.ISBN;
   }

