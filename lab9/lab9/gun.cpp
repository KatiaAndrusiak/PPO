#include "gun.h"

//konstruktor 
Gun::Gun(int N, double caliber){
    _N=N;
    _i=0;
    _caliber=caliber;
    tab=new Bullet *[_N];
    for(int j=0; j<_N; j++){
        tab[j]= new Bullet(_caliber);
        _i++;
    }
    
    
}
// konstructor kopijujacy
Gun::Gun(const Gun & gun){
    _N=gun._N;
    _i=gun._i;
    _caliber=gun._caliber;

  tab= new Bullet*[_N];
  for(int i=0; i<_i; i++){
          tab[i]=new Bullet(_caliber);
  }
  for(int i=_i; i<_N; i++){              
         tab[i]=nullptr;
  }

  if (gun.komora)  komora=new Bullet(); 
  else komora=nullptr;    
    
    std::cout<<"----copy----"<<std::endl;

}


   Gun::Gun(Gun &&gun){
       tab=gun.tab;
       gun.tab=nullptr;
       komora=gun.komora;
       gun.komora=nullptr;
       _i=gun._i;
       gun._i=0;
       _caliber=gun._caliber;
       gun._caliber=0;
       _N=gun._N;
       gun._N=0;
       std::cout<<"----prenoszacy----"<<std::endl;

   }

//destruktor
Gun::~Gun(){
    if(tab){
    for(int i=0; i<_i; i++){
        delete tab[i];
    }
    delete [] tab;
    }
 std::cout<<"----destruktor----"<<std::endl;
 if(komora){
   delete komora; 
 }
}

//naladowanie magazynu
void Gun::load(){
 if(_i>0){
     komora= new Bullet(_caliber);
     
     //z tym mi nie dziala :(
     delete tab[_i-1];
    tab[_i-1]=nullptr;
     _i--;
 
 }
 else{
     
     mag_empty();
 }
}
//strzal
void Gun::pull_trigger(){
  if(komora!=nullptr){
        bang();
        delete komora;
        komora=nullptr;
          }
  else{
      
      chamb_empty();
  }

}

// przeladowania stralu
void Gun::pull_trigger(int n){
    if(n<=_N){
    for(int i=0; i<n; i++){
        load();
        pull_trigger();
    }
 } 
}

//funkcja dla stworzenia nowego magazynu
void Gun::new_magazine(){
  
    for(int j=0; j<_N; j++){
        tab[j]= new Bullet(_caliber);
        _i++;
    }
  }

