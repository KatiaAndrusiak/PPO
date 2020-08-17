#ifndef Matrix_h
#define Matrix_h
#include "Vector.h"

class Matrix {
public:
    Matrix( int i,  int j, int value );
    ~Matrix();
	Vector & at( int index);
    void print() const;
private:
    Vector ** _matrix;
    int _rows;
};

#endif