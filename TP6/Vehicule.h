
#ifndef TP6_VEHICULE_H
#define TP6_VEHICULE_H

#include "Point.h"
#include <cstring>
#include <iostream>
#include <cmath>

class Vehicule {
private :
    char* identifier;
    Point position;
public :
    Vehicule();
    Vehicule(Point p,char* id);//attention il y a une poiteur en parametre
    Vehicule(Vehicule const & v);

    void afficherV();
    void setId(char* id);
    char* getId();
    void setPosition(Point p);

    Point getPosition();

    float moveTo(Point p);
    float moveTo(Vehicule& v);
    float moveTo(int x, int y);

    void reset();

    ~Vehicule();
};
#endif //TP6_VEHICULE_H
