//
// Created by Théo on 11/10/2019.
//
#include <iostream>
#include <cmath>

#ifndef TP2_EQUATION_H
#define TP2_EQUATION_H

class Equation{
private:
    double a;
    double b;
    double c;

public:
    //fct
    void result();
    //manipulateur
    void setA(double a);
    void setB(double b);
    void setC(double c);
    //accesseurs
    double getA();
    double getB();
    double getC();

    double image(double x);
};
#endif //TP2_EQUATION_H
