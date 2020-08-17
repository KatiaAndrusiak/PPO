#include "intArrayList.h"
#include <iostream>

    IntArrayList::IntArrayList(int MaxSize){
        size=0;
        maxSize=MaxSize;
        tab=new int [maxSize];
    }

    ///////////////////////////////////

    IntArrayList::IntArrayList(){
        size=0;
        tab=new int [maxSize];
    }

    //////////////////////////////////

     void IntArrayList::add(int a){
         if(size<maxSize){
             tab[size]=a;
             size++;
         }
     }

     //////////////////////////////////

    void IntArrayList::print(){
        std::cout<<"[";
        for(int i=0; i<size-1; i++){
            std::cout<<tab[i]<<",";
        }

        std::cout<<tab[size-1]<<"]"<<size<<std::endl;
    }

//////////////////////////////////////

    void IntArrayList::add(int* array, int s)
    {
        if (size+s<maxSize)
        {
            int a=size;
            for(int i=a+s-1; i>=a; i--)
            {
                    tab[i]=array[--s];
                    size++;
            }  
        }
        else{
            return;
        }
    }
    //////////////////////////////
    int IntArrayList::find(int b){
        for(int i=0; i<size; i++){
            if(tab[i]==b)
                return i;
            }
          return -1;  
        }


//////////////////////////////////
    void IntArrayList::printFind(int b){
        if(find(b)>=0){
            std::cout<<"Wartosc="<<b<<"    Indeks="<<find(b)<<std::endl;
        }
        else{
         std::cout<<"Wartosc="<<b<<"    Element nieznaleziony"<<std::endl;
        }
    }
////////////////////////////////////////////////
        void IntArrayList::remove(int b){
            int ix=find(b);
                tab[ix]=0;
                for(int i=ix; i<size-1; i++){
                    tab[i]=tab[i+1];
                }
                size--;
        }

////////////////////////////////////////////////////
    void IntArrayList::add(const int index, int new_a){
        size++;
        for(int i=size-1; i>index; i--){
                    tab[i]=tab[i-1];
                }
        tab[index]=new_a;
    }
////////////////////////////////////////////////

    void IntArrayList::remove(int b, int n){
        int ix=find(b);
        for(int i=ix; i<ix+n; i++)
            tab[i]=0;
         for(int i=ix; i<size; i++){
            tab[i]=tab[i+n];
         }
        size=size-n;
    }

    ////////////////////////////////////
    void IntArrayList::add(int a, bool zm){
        if(zm==true){
            tab[size]=a;
            size++;
            bubbleSort(tab,size); 
            
        }
    }


void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)  {   
    for (j = 0; j < n-i-1; j++){  
        if (arr[j] > arr[j+1]){  
            int temp =arr[j];   
            arr[j] = arr[j+1];  
            arr[j+1] =temp; 
        }
     }
    }   
}  




