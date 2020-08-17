#include "Matrix.h"
#include "Vector.h"
#include <iostream>

Matrix::Matrix( int i,  int j, int value ){
    _rows=i;
    _matrix= new Vector *[_rows];
    for(int i = 0; i < _rows; i++)
         _matrix[i] = new Vector(j, value);
    
}

Matrix::~Matrix()
{
		for(int i=0; i<_rows; i++)
            delete _matrix[i];
        delete [] _matrix;
}

Vector & Matrix::at( int index){
    return *(_matrix)[index];
}
////////////////////////////
void Matrix::print() const{
		for(int i = 0; i < _rows; i++){
			_matrix[i]->print();
			std::cout << std::endl;
		}
}