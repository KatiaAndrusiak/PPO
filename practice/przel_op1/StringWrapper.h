#ifndef StringWrapper_h
#define StringWrapper_h
#include <iostream>

class StringWrapper{
public:
    StringWrapper();
    StringWrapper(const char *str);
    ~StringWrapper();
    friend StringWrapper operator*(const int count, const StringWrapper& str);
    bool operator==(const StringWrapper &str) const;
    StringWrapper operator+(const StringWrapper &str)const;
    StringWrapper operator*(int count)const;
    StringWrapper & operator=(const StringWrapper &str);
    //StringWrapper & operator=(StringWrapper &&str);
    friend std::ostream & operator<<(std::ostream & output, const StringWrapper &str);
    


    //friend bool operator==(const StringWrapper &str1,const StringWrapper &str2);

private:
     char* _str;
};

std::ostream & operator<<(std::ostream& output, const StringWrapper &str);
StringWrapper operator*(const int count, const StringWrapper& str);


//bool operator==(const StringWrapper &str1,const StringWrapper &str2);

#endif