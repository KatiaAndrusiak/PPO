#include "polynomial.h"
#include <cmath>
#include <utility>

    //Konstruktor dwuargumentowy
    Polynomial::Polynomial(int count, double *wsp) : _count(count+1)
    {
        _wsp=new double[_count];
        for(int i=0; i<_count; i++){
            _wsp[i]=wsp[i];
        }
    }

    //Konstruktor jednoargumentowy
    Polynomial::Polynomial(int count) : _count(count+1)
    {
        _wsp=new double[_count]{0};
    }

    //Konstruktor kopiujacy
    Polynomial::Polynomial(const Polynomial & pol)
    {
        _count=pol._count;
        _wsp=new double [_count];
        for(int i=0; i<_count; i++)
        {
            _wsp[i]=pol._wsp[i];
        }
    }

    //Konstrutor przenoszacy
    Polynomial::Polynomial(Polynomial && pol)
    {
        _count=std::move(pol._count);
        pol._count=0;
        _wsp=std::move(pol._wsp);
        pol._wsp=nullptr;
    }

    //Destruktor
    Polynomial::~Polynomial()
    {
        if(_wsp)
         delete [] _wsp;
    }

    //Operator () wyliczający wartość wielomianu dla zadanego argumentu
    double Polynomial::operator()(double x)
    {
        double sum=0;
        sum=_wsp[0];
        for(int i=1; i<_count; i++){
            sum+=_wsp[i]*pow(x,i);
        }
        return sum;
    }
    
    //Operator przypisania kopiującego
    Polynomial & Polynomial::operator=(const Polynomial &pol)
    {
        if(this==&pol) return *this;

        delete [] _wsp;
        
        _count=pol._count;
        _wsp=new double [_count];
        for(int i=0; i<_count; i++)
        {
            _wsp[i]=pol._wsp[i];
        }
        return *this;
    }

    //Operator przypisania przenoszacego
    Polynomial & Polynomial::operator=(Polynomial &&pol)
    {
        if(this==&pol) return *this;

        delete [] _wsp;
        
        _count=std::move(pol._count);
        pol._count=0;
        _wsp=std::move(pol._wsp);
        pol._wsp=nullptr;
        return *this;
    }

    //Operator += dodający wielomiany
    Polynomial & Polynomial::operator+=(const Polynomial& pol)
    {
        if(_count>=pol._count)
        {
            for(int i=0; i<pol._count; i++)
                _wsp[i]+=pol._wsp[i];
            return *this;   
        }
        else if(_count<pol._count){
            double *tmp=new double[pol._count]{0};

            for(int i=0; i<_count; i++)
            {
                tmp[i]=_wsp[i]+pol._wsp[i];
            }
            for(int i=_count; i<pol._count; i++)
            {
                tmp[i]=pol._wsp[i];
            }
            delete [] _wsp;
            _count=pol._count;
            _wsp=tmp; 
        }
        return *this;
    }

    //Operator * mnożący wielomian przez liczbę 
    Polynomial operator*(const Polynomial & pol,const double k){
        Polynomial tmp(pol);
        for(int i=0; i<pol._count; i++){
            tmp._wsp[i]*=k;
        }
        return tmp;
    }

    //Operator << drukujący wielomian
    std::ostream & operator<<(std::ostream & out, const Polynomial & pol)
    {
        if(pol._count==1){
            out<<pol._wsp[0];
        }
        else
        {
            if(pol._wsp[0]!=0) 
                out<<pol._wsp[0];
            for(int i=1; i<pol._count; i++)
            {
                if(pol._wsp[i]>0)
                {
                    out<<" +"<<pol._wsp[i]<<"*x^"<<i;
                }
                else if(pol._wsp[i]<0)
                {
                    out<<" "<<pol._wsp[i]<<"*x^"<<i;
                }
            }
        }
        return out;
    }