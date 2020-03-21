//
// Created by Théo on 1/23/2020.
//

#include "Subject.h"

void Subject::addObserver(shared_ptr<Observer> p) {
    this->Oversers.push_back(p);
}

void Subject::notifyObersers() {
    for(vector<shared_ptr<Observer>>::iterator it = this->Oversers.begin(); it != this->Oversers.end(); it ++ ){
        *it.update();
    }
}
