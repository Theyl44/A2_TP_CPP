//
// Created by Théo on 29/11/2019.
//
#include <iostream>
using namespace std;

#ifndef TP4_RATIONAL_H
#define TP4_RATIONAL_H
class Rational{
private :
    int numerator;
    int denominator;

public:
    Rational();
    Rational(int n, int d);
    Rational(Rational const& p);

    void setN(int N);
    void setD(int D);

    int getN();
    int getD();

    void afficher();
    Rational reduce();
    bool equFract(Rational r1);//0 si non et 1 si oui
    Rational sumFract(Rational r1);
    Rational prodFract(Rational r1);


    int pgcd(int a, int b) ;
    int ppcm(int a , int b);

};
#endif //TP4_RATIONAL_H
