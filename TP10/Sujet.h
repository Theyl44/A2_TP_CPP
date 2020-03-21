//
// Created by Théo on 1/23/2020.
//

#ifndef TP10_SUJET_H
#define TP10_SUJET_H

#include "Observateur.h"
#include <vector>
#include <memory>
using namespace std;

class Sujet {
protected:
    vector<shared_ptr<Observateur>> Observateurs;
public:
    virtual void addObservateur();
    virtual void notifObservateurs();

};


#endif //TP10_SUJET_H
