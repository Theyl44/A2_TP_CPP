//
// Created by Théo on 1/24/2020.
//

#ifndef TP10_OBSERVER_H
#define TP10_OBSERVER_H

#include <memory>
#include "ObservablePoint.h"
class Observer {
public:
    virtual void update(shared_ptr<ObservablePoint> ptrs);

};


#endif //TP10_OBSERVER_H
