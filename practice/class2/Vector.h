#ifndef Vector_h
#define Vector_h

class Vector{
public:
    Vector();
    Vector(int size, int value);
    void print();
    void mul(int a);
    Vector & add(const int value);
    void add(Vector & vectorToAdd);
    int & at(int c);


private:
    int *tab;
    int Size;
};
#endif
