#ifndef MapPoint_h
#define MapPoint_h

class MapDistance{
public:
    MapDistance();
    void Print();
    ~MapDistance(){
        delete [] cities;
    }

    char* cities;
    double d_latitude;
    double d_longitude;
};

class MapPoint{
public:
    MapPoint(const char* city, double latitude, double longitude);
    MapPoint(const char* city);
    MapPoint();
    ~MapPoint();
    void Longitude(const double longitude);
    void Latitude(const double latitude);
    void SetId(const char* city);
    void Coordinates(const double latitude, const double longitude);
    void Print();

    MapDistance Distance(const MapPoint &city);

    MapPoint Farthest(const MapPoint &city1, const MapPoint &city2);
  
 private:
    const char* c_city;
    double c_latitude;
    double c_longitude;
};

///////////////////////////////////



#endif