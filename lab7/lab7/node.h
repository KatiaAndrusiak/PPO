#ifndef node_h
#define node_h
#include "coin.h"
class Node{
public:
    static int get_tot_nodes();
    friend class Stack;
private:
    Node(Coin &moneta);
    Coin *_obiect;
    Node *_prev;
    static int n;
};

#endif