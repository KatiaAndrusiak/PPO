#ifndef stack_h
#define stack_h
#include "coin.h"
#include "node.h"

class Stack{
public:
    Stack( Coin &moneta);
    void push( Coin &moneta);
    Coin * pop();
private:
    Node *lista;
};

#endif