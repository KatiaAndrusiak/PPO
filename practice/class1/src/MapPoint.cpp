#include "MapPoint.h"
#include <iostream>
#include <cstring>
#include <cmath>

    MapPoint::MapPoint(const char* city, double latitude, double longitude){
       c_city=city;
       c_latitude=latitude;
       c_longitude=longitude; 
    }
    //////////////////
    void MapPoint::Print(){
        std::cout<<"Point: "<<c_city<<" ("<<c_latitude<<", "<<c_longitude<<")"<<std::endl;
    }
    //////////////
    MapPoint::MapPoint(const char* city){
        c_city=city;
    }
    /////////////////////////////////
    void MapPoint::Longitude(const double longitude){
        c_longitude=longitude;
    }
    /////////////////////////////
    void MapPoint::Latitude(const double latitude){
         c_latitude=latitude;
     }
     ////////////////////////
    MapPoint::MapPoint(){
        c_latitude=0;
        c_longitude=0;
    }

    void MapPoint::SetId(const char* city){
          c_city=city;
      }
      //////////////////////////////
    void MapPoint::Coordinates(const double latitude, const double longitude){
        c_latitude=latitude;
        c_longitude=longitude;
    }

    ///////distance/////
    MapDistance::MapDistance(){
        cities = new char[5];
        strcpy(cities, "none");
        d_latitude=0;
        d_longitude=0;
    }
    ///////////////////

    void MapDistance::Print(){
        std::cout<<"Distance: "<<cities<<" ("<<d_latitude<<", "<<d_longitude<<")"<<std::endl;
    }
    ///////////////////
    MapDistance  MapPoint::Distance(const MapPoint &city){
        MapDistance miasto;
        miasto.d_latitude=-c_latitude+city.c_latitude;
        miasto.d_longitude=city.c_longitude-c_longitude;
        strcpy(miasto.cities, c_city);
        strcat(miasto.cities, "-");
        strcat(miasto.cities, city.c_city);
        return miasto;
    }

    //////////////////////////////////////////

    MapPoint MapPoint::Farthest(const MapPoint &city1, const MapPoint &city2){
        double delta_lat=city1.c_latitude-c_latitude;
        double delta_lon=city1.c_longitude-c_longitude;
        double x1=sqrt((delta_lat*delta_lat)+(delta_lon*delta_lon));
        double delta_lat2=city2.c_latitude-c_latitude;
        double delta_lon2=city2.c_longitude-c_longitude;
        double x2=sqrt((delta_lat2*delta_lat2)+(delta_lon2*delta_lon2));
        if(x1>x2){
            return city1;
        }
        else
        {
            return city2;
        }
    }









