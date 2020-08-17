#include <iostream>
#include <string>

class Number{
public:
   explicit Number(int n=0): _n(n){}
    int Get()const { return _n; }

private:
    int _n;
};

class Frac{
public:
    friend Frac Multiply(const Frac& frac1, const Frac & frac2);
    friend Frac multi1(Frac *a, Frac *b);
    friend Frac multi2(Frac &a, Frac &b);

    Frac() : _licznik(0), _mianownik(1) {}
    Frac(int l, int m): _licznik(l), _mianownik(m) {}
    explicit Frac(int l): _licznik(l), _mianownik(1) {std::cout<<"Konst konw"<<std::endl; }
   explicit Frac(const Number& n): _licznik(n.Get()), _mianownik(1){}

    void print() { 	std::cout << _licznik << "/" << _mianownik << std::endl; }

   explicit operator double() const{ 
        std::cout << "\nDziala funkcja konwertujaca do double." << std::endl;
        return (double)_licznik/(double)_mianownik;
    }

   explicit operator Number()const{ 
        std::cout << "\nDziala funkcja konwertujaca do Number." << std::endl;
		return Number((int)((double)_licznik/(double)_mianownik + 0.5));
    }

  
private:
    int _licznik;
    int _mianownik;
};



Frac Multiply(const Frac& frac1, const Frac & frac2){
    Frac tmp;
    tmp._licznik=frac1._licznik*frac2._licznik;
    tmp._mianownik=frac1._mianownik*frac2._mianownik;
    return tmp;
}

///////////////
Frac multi1(Frac *a, Frac *b)
{
	Frac tmp;
	tmp._licznik = a->_licznik * b->_licznik;
	tmp._mianownik = a->_mianownik * b->_mianownik;
	return tmp;
}
Frac multi2(Frac &a, Frac &b)
{
	Frac tmp;
	tmp._licznik = a._licznik * b._licznik;
	tmp._mianownik = a._mianownik * b._mianownik;
	return tmp;
}
//////////////////////
double sum(double a, double b)
{
	return a + b;
}
//////////////////////////////
int sum2(const Number& a, const Number& b)
{
	return a.Get() + b.Get();
}

////////////////////////////////
int main(){

    double  x = 1.75;
	int b;
	b = static_cast<int>(x);


    Frac fraction1;
    Frac fraktion2(3,2);
    const Frac fraktion3(3,2);
    fraction1=multi1(&fraktion2,const_cast<Frac*>(&fraktion3));
    fraction1=multi2(fraktion2,const_cast<Frac&>(fraktion3));

    fraction1=Multiply(fraktion2,Frac(10)); //fraction1=Multiply(fraktion2,10); jesli nie uzywamy explicit!
    fraction1.print();
    int n=5;
    fraction1=Multiply(fraktion2,Frac(n));
    fraction1.print();

    std::cout<<sum(1.5,(double)(fraktion2) )<<std::endl;
    std::cout<<1 - static_cast<double>(fraktion2) <<std::endl;

    Number number1(3);

    	std::cout << sum2(number1, (Number)(fraktion2)) << std::endl;
        std::cout<< (double)(Multiply((Frac)(number1), fraktion2)) << std::endl;

    std::cout<<"--Suma"<<sum2(number1,static_cast<Number>(fraktion2))<<std::endl;
   return 0; 
}