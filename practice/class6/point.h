#ifndef point_h
#define point_h
#include <string> 
class Point;
int compareX(const Point &a, const Point &b);
int compareY(const Point &a, const Point &b);
int compareXY(const Point &a, const Point &b);
//typedef int(*wsk)(const Point &, const Point &);
//void directions(const Point &a, const Point &b, wsk cmp);

void directions(const Point &a, const Point &b, std::string cmp);
class Point{
public:
    Point();
    Point(double x, double y);
    Point(const char *name, double x, double y);
    Point(const Point& point);
    Point(Point &&point);
    ~Point();
    void fullPrint();
    void changeName(const char* name);
    void move(double x, double y);
    friend  int compareX(const Point &a, const Point &b);
    friend int compareY(const Point &a, const Point &b);
    friend int compareXY(const Point &a, const Point &b);
    friend void directions(const Point &a, const Point &b, std::string cmp);


private:
    char *_name;
    double _x;
    double _y;
};




#endif