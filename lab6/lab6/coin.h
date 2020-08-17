#ifndef coin_h
#define coin_h

enum coin{
    one=1,
    two=2,
    five=5 };
///////////////////////////////////////////////////
enum side{
    heads=0,
    tails=1 };
/////////////////////////////////////////////////////
class Coin{
public:
    int get_coin_value();
    void print_side_up();
    void toss();
    side get_side_up();
    Coin(coin cop);
    Coin();
private:
    coin value;
    side Side;
};
/////////////////////////////////////////////////

#endif