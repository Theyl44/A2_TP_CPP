//
// Created by Théo on 1/23/2020.
//

#ifndef TP10_STATIONMETEO_H
#define TP10_STATIONMETEO_H

#include "Sujet.h"
#include "Observateur.h"
#include <memory>
#include <iostream>
using namespace std;

class StationMeteo : public Sujet {
private:
    float temperature;

public:
    StationMeteo(float t);
    virtual void addObservateur(shared_ptr<Observateur> p);
    virtual void notif();
    void setTemperateur(float t);
};
#endif //TP10_STATIONMETEO_H
