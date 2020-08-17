#include "stack.h"
#include "coin.h"
#include "node.h"


    Stack::Stack( Coin &moneta){
        lista = new Node(moneta);
        lista->_prev=nullptr;
        
    
    }
//////////////////////////////////

    void Stack::push( Coin &moneta){
    Node *list = new Node(moneta);
    list->_prev=lista;
    lista=list;
    }

///////////////////////////////////

    Coin * Stack::pop(){
       if(lista == nullptr)
       {
        return nullptr;
       }
       
        Coin *zmienna=lista->_obiect;
        Node *tmp=lista;
        lista=lista->_prev;
        delete tmp;
        return zmienna; 
    }