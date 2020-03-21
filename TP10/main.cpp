#include <iostream>
#include <memory>
#include "StationMeteo.h"
#include "Agriculteur.h"
#include "ObservablePoint.h"
#include "PointObserver1.h"
#include "PointObserver2.h"
void scenario1(){
    StationMeteo* meteo = new StationMeteo(10 );
    shared_ptr<Agriculteur> agri(new Agriculteur(1));
    meteo->addObservateur(agri);
    meteo->setTemperateur(11);
}
void scenario2(){
    ObservablePoint observablePoint(0,0);

    observablePoint.addObserver(
            shared_ptr<PointObserver1>(new PointObserver1));

    observablePoint.addObserver(
            shared_ptr<PointObserver2>(new PointObserver2()) );



    observablePoint.moveTo(10, 10);
    cout << "---" << endl;
    observablePoint.moveTo(42, 0);
}
int main() {
//    scenario1();
    scenario2();
    return 0;
}
