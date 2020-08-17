#ifndef robots_h
#define robots_h

#include <iostream>
#include <cstdlib>
#include <string>

 typedef struct position {
     int x;
     int y;
 }Position;

 typedef struct robot{
     const char *name;
     Position post;
 }Robot;

 Robot **tab_rob=new Robot *[5];
 int numofrob=0;

 Robot *InitializeRobot(const char *name, Position point)///utworzenie robota
 {
     Robot *roob=new Robot;
     roob->name=name;
     roob->post=point;
     for(int i=0; i<numofrob; i++){
        if(roob->post.x ==tab_rob[i]->post.x && roob->post.y == tab_rob[i]->post.y){
            std::cout << "InitializeRobot: Two robots cannot be placed in the same position."<< std::endl;
            delete roob;
           return nullptr;
        }
     }  
     if(numofrob>=5){
        std::cout<<"InitializeRobot: No space for an additional robot."<<std::endl;
         delete roob;
        return nullptr;
     }
     tab_rob[numofrob]=roob;
     numofrob++;
  return roob;
 }

 Robot *InitializeRobot(Position point)///utworzenie robota bez imia
  {
  return InitializeRobot("noname",point);
 }

void EchoRobot(Robot *robo){
    if(robo!=nullptr){
        std::cout << "> Hello, I'm robot "<<robo->name<<" at x="<<robo->post.x<<", y="<<robo->post.y<<"."<<std::endl;
    }else{
        std::cout << "EchoRobot: No such robot."<<std::endl;
    }
}

void MoveX (Robot *roboo, int xx) ///przesuwa x
{
   int samerob=0;
    for(int i=0; i<numofrob; i++){
        if(roboo->post.x+xx==tab_rob[i]->post.x && roboo->post.y==tab_rob[i]->post.y){
            samerob++;
            std::cout<<"MoveX: Cannot place robots in the same position."<<std::endl;
        }
    }
        if(samerob==0)
        (*roboo).post.x+=xx;
}

void MoveY (Robot *roboo, int yy)///przesuwa y
{
 int samerob=0;
    for(int i=0; i<numofrob; i++){
        if(roboo->post.x==tab_rob[i]->post.x && roboo->post.y+yy==tab_rob[i]->post.y){
            samerob++;
             std::cout<<"MoveY: Cannot place robots in the same position."<<std::endl;
        }
    }
    if(samerob==0)
        (*roboo).post.y+=yy;  
}

typedef void (*Operation)(Robot *, int a);///wskaznik na funkcji przesuniecia


void DeleteRobots(void){
    for(int i=0; i<numofrob; i++){
       delete tab_rob[i];
    }
delete [] tab_rob;
}

#endif
