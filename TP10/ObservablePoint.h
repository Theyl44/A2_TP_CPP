//
// Created by Théo on 1/23/2020.
//

#ifndef TP10_OBSERVABLEPOINT_H
#define TP10_OBSERVABLEPOINT_H
#include "Subject.h"
#include "Point.h"

class ObservablePoint : public Subject, public Point{
public:
    ObservablePoint(float x, float y);
    void addObserver(shared_ptr<Observer>);
    void notifyObersers();
    void moveTo(float x, float y);

};


#endif //TP10_OBSERVABLEPOINT_H
