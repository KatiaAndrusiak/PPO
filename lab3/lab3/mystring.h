#ifndef mystring_h
#define mystring_h

///tworze strukture
typedef struct mystr{
    const char * str;
    int length;
}MyString;
MyString * CreateString(const char *str);

void ClearStrings(void);


void PrintMyString(MyString *str);

#endif