//
// Created by Théo on 1/23/2020.
//

#include "ObservablePoint.h"

void ObservablePoint::addObserver(shared_ptr<Observer>) {

}

void ObservablePoint::notifyObersers() {
    for(vector<shared_ptr<Observer>>::iterator it = this->Oversers.begin() ; it != this->Oversers.end();it++){

    }
}

void ObservablePoint::moveTo(float x, float y) {
    this->setX(x);
    this->setY(y);
    this->notifyObersers();
}

ObservablePoint::ObservablePoint(float x, float y)
:Point(x,y)
{

}
