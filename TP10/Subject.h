//
// Created by Théo on 1/23/2020.
//

#ifndef TP10_SUBJECT_H
#define TP10_SUBJECT_H

#include <memory>
#include <vector>
#include "Observer.h"

using namespace std;

class Subject {
protected:
    vector<shared_ptr<Observer>> Oversers;
public:
    virtual void addObserver(shared_ptr<Observer> p);

    virtual void notifyObersers();
};


#endif //TP10_SUBJECT_H
