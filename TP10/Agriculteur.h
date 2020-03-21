//
// Created by Théo on 1/23/2020.
//

#ifndef TP10_AGRICULTEUR_H
#define TP10_AGRICULTEUR_H

#include "Observateur.h"

class Agriculteur : public Observateur {
private:
    double id;

public :
    Agriculteur(double t);
    void notifObservateur();
    void notif();
};


#endif //TP10_AGRICULTEUR_H
