//
// Created by Théo on 1/23/2020.
//

#ifndef TP10_POINTOBSERVER2_H
#define TP10_POINTOBSERVER2_H

#include "Observer.h"
#include <iostream>
using namespace std;

class PointObserver2 : public Observer{
private:
public:
    virtual void update(shared_ptr<ObservablePoint> ptrs);
};


#endif //TP10_POINTOBSERVER2_H
