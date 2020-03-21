#include "Vehicule.h"

void gasVehicleCopyTest(){
    GasVehicle original(Point(25,3), "XY-358-PQ", 60, 6.8, 95);
    GasVehicle copy = original;
    original.setId("XXX");
    original.afficher();
    copy.afficher();
}
void dieselVehicleDestructionTest() {
    DieselVehicle* dieselVehicle = new DieselVehicle(Point(2, 10), "HD-888-ZY",40, 5.5, true);
    Vehicule* vehicle = dieselVehicle; // upcast
    delete vehicle;
}
void octaneRatingConsumptionTests(){
    GasVehicle gasVehicle95(Point(0,0), "XY-358-PQ", 30, 5, 95);
    cout << "Traveled distance : " << gasVehicle95.moveTo(0, 100) << endl;
    gasVehicle95.afficher();
    GasVehicle gasVehicle98(Point(0,0), "HD-888-ZY", 30, 5, 98);
    cout << "Traveled distance : " << gasVehicle98.moveTo(0, 100) << endl;
    gasVehicle98.afficher();
}
int main() {

//    gasVehicleCopyTest();
//    dieselVehicleDestructionTest();
    octaneRatingConsumptionTests();
    return 0;
}