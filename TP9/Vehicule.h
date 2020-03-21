
#ifndef TP6_VEHICULE_H
#define TP6_VEHICULE_H

using namespace std;
#include "Point.h"
#include <cstring>
#include <iostream>
#include <cmath>

class Vehicule {
private :
    char* identifier;
    Point position;

protected:
    float carburant;
    float consommation;

public :
    Vehicule();
    Vehicule(Point p,char* id, float carburant , float consommation);//attention il y a une poiteur en parametre
    Vehicule(Vehicule const & v);

    virtual void afficher();
    void setId(char* id);
    char* getId();
    void setPosition(Point p);

    Point getPosition();

    float moveTo(Point p);
    float moveTo(Vehicule& v);
    float moveTo(int x, int y);

    void reset();

    void setConsommation(float d);
    void setCarburant(float d);
    float getConsommation();
    float getCarburant();

    virtual ~Vehicule();
};
/*
 *
DIESEL
 *
 */

class DieselVehicle : public Vehicule
{
private:
    bool filtreAParticules;

public:
    DieselVehicle(Point p, char* name, float carburant, float consommation,bool b = true);
    DieselVehicle(DieselVehicle & p);
    ~DieselVehicle();
    bool getFiltreAParticules();
    void setFiltreAParticules(bool b);
    void afficher();
};

/*
 *
 GAS
 *
 */

class GasVehicle : public Vehicule
{
private:
    int octaneRate;

public:
    GasVehicle(Point p, char* name, float carburant, float consommation,int octaneRate);
    GasVehicle(GasVehicle &p);
    ~GasVehicle();
    int getOctaneRate();
    void setOctaneRate(int octanerate);
    void afficher();

};
#endif //TP6_VEHICULE_H
