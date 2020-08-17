#ifndef piggybank_h
#define piggybank_h

class Piggybank{
public:
    Piggybank(int rozm);
    ~Piggybank();
    void put_coin(Coin &pln);
    int get_tot_value();
private:
    int size;
    Coin *tab;
    int ix;
    int sum;
   
};


#endif