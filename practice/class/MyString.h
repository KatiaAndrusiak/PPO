#ifndef MyString_h
#define MyString_h

class MyString
{
private:
    char *zmienna;
public:
    MyString(const char *napis);
    char* str();
   void join(const MyString &zm);
   void replace(const char* str);
   ~MyString();

};

void swap (MyString &s1, MyString &s2);


#endif