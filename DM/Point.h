#include <cmath>
#include <iostream>
#include <cstdlib>

#ifndef DM_POINT_H
#define DM_POINT_H

class Point_part1{//tout en public
public:
    double x;
    double y;

    double distance(Point_part1 P);
    Point_part1 milieu(Point_part1 P);
    void saisir();
    void afficher();
};

class Point_part3{//avec x,y en attributs
private:
    double x,y;
public:
    void setX(double x);
    void setY(double y);

    double getX();
    double getY();

    void saisir();
    void afficher();
};

class Point_part4{//alloc dynamique
private:
    double x;
    double y;
public:
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();

    Point_part4* milieu(Point_part4* P);
    double distance( Point_part4* P);

    void saisir();
    void afficher();

};


#endif //DM_POINT_H
