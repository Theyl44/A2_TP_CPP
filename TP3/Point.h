//
// Created by Théo on 12/11/2019.
//
#include <iostream>
#include <cmath>

#ifndef TP3_POINT_H
#define TP3_POINT_H

class Point{
private:
    double x;
    double y;

public:
    Point();//const def
    Point(double x);
    Point(double x , double y);
    Point(const Point& p);

    void setPoint(double x, double y);
    double getX();
    double getY();

    Point milieu(Point& P);
    double distance(Point& P);
    void afficher();

    void saisie(Point& p1,Point& p2);
    void result(Point& p1,Point& p2);
};

#endif //TP3_POINT_H
