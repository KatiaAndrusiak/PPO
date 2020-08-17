#ifndef PointAverage_h
#define PointAverage_h
#include "stddef.h"
class PointAverage;
class Point2D{
public:
    Point2D(): _x(0), _y(0) { }
    Point2D(double x, double y): _x(x), _y(y) { }
    void Print();
    Point2D & operator--();
    Point2D  operator++(int);
    Point2D operator+(const Point2D &point);
    static void * operator new(size_t size);
    friend Point2D operator+(double a, const Point2D & point);
    ~Point2D()=default;
    static void operator delete(void* wsk);

    friend class PointAverage;
private:
    double _x;
    double _y;
};

Point2D operator+(double a, const Point2D & point);

class PointAverage
{
public:
    PointAverage();
    ~PointAverage()=default;
    void operator()(const Point2D &pnt);
    void Print();
    void Reset();


private:
    int index;
    Point2D point;
};


#endif