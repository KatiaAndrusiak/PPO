#ifndef book_h
#define book_h
#include <iostream>

enum Genre{
    thiller=1, crime=2 ,sci_fi=3 ,undefined=0
};

class Book{
public:
friend class Library;
 std::string get_author(){  return autor; }
 Book();
 Book(std::string tytul_, std::string autor_,short unsigned rok_, Genre gatunek_, long unsigned ISBN_);
 Book(const Book& book);
 Book( Book&& book);

 //operatory konwersji
 operator std::string() const{
        return tytul;
}
operator short unsigned() const{
    return rok;
}
operator long unsigned() const{
    return ISBN;
}
operator Genre() const{
    return gatunek;
}

private:
    std::string tytul;
    std::string autor;
    short unsigned rok;
    Genre gatunek;
    long unsigned ISBN;
};

#endif