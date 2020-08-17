#include "node.h"
#include "coin.h"

int Node::n;

    int Node::get_tot_nodes(){
       return n; 
    }

    Node::Node(Coin &moneta){
        _obiect=new Coin(moneta);
        n++;
    }
