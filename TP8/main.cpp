#include <iostream>
#include "Point.h"
#include "Vehicule.h"
using namespace std;

void displayTests1();
void displayTests2();
void TestGasV();
void TestDieselV();
void consumptionTests();

int main() {
//    displayTests1();
//    displayTests2();
//    TestGasV();
//    TestDieselV();
    consumptionTests();


    return 0;
}
void displayTests1(){

    Vehicule vehicle(Point(5,6), "CC-987-JU", 50, 5.3);

    GasVehicle gasVehicle(Point(25,3), "XY-358-PQ", 60, 6.8, 95);

    DieselVehicle dieselVehicle(Point(2,10), "HD-888-ZY", 40, 5.5, true);

}
void TestGasV(){
    GasVehicle gasVehicle(Point(0,0)," ", 0 , 0 ,0);

    cout << "La plaque d'immatriculation est : " << gasVehicle.getId() << " et la position du véhicule est : " << gasVehicle.getPosition().getX() << "," << gasVehicle.getPosition().getY() <<  " !" << endl;
    cout << "Le carburant restant du véhicule est : " << gasVehicle.getCarburant() << "L et sa consommation est : " << gasVehicle.getConsommation() << "L/100kms ! De plus son indice en octane est : " << gasVehicle.getOctaneRate() << " !" << endl;


    gasVehicle.setConsommation(7.5);
    gasVehicle.setCarburant(57);
    gasVehicle.setId("BL-372-SW");
    gasVehicle.setOctaneRate(74);
    gasVehicle.setPosition(Point(7.5,24));

    cout << endl << "La plaque d'immatriculation est : " << gasVehicle.getId() << " et la position du véhicule est : " << gasVehicle.getPosition().getX() << "," << gasVehicle.getPosition().getY() <<  " !" << endl;
    cout << "Le carburant restant du véhicule est : " << gasVehicle.getCarburant() << "L et sa consommation est : " << gasVehicle.getConsommation() << "L/100kms ! De plus son indice en octane est : " << gasVehicle.getOctaneRate() << " !" << endl;

}
void TestDieselV(){
    DieselVehicle dieselVehicle(Point(0,0)," ", 0 , 0 );

    cout << "La plaque d'immatriculation est : " << dieselVehicle.getId() << " et la position du véhicule est : " << dieselVehicle.getPosition().getX() << "," << dieselVehicle.getPosition().getY() <<  " !" << endl;
    cout << "Le carburant restant du véhicule est : " << dieselVehicle.getCarburant() << "L et sa consommation est : " << dieselVehicle.getConsommation() << "L/100kms ! De plus, ce véhicule";
    if(dieselVehicle.getFiltreAParticules()){
        cout << " dispose";
    } else {
        cout << " ne dispose pas";
    }
    cout << " d'un filtre à particules" << endl;

    dieselVehicle.setConsommation(7.5);
    dieselVehicle.setCarburant(57);
    dieselVehicle.setId("BL-372-SW");
    dieselVehicle.setFiltreAParticules(false);
    dieselVehicle.setPosition(Point(7,24));

    cout <<endl << "La plaque d'immatriculation est : " << dieselVehicle.getId() << " et la position du véhicule est : " << dieselVehicle.getPosition().getX() << "," << dieselVehicle.getPosition().getY() <<  " !" << endl;
    cout << "Le carburant restant du véhicule est : " << dieselVehicle.getCarburant() << "L et sa consommation est : " << dieselVehicle.getConsommation() << "L/100kms ! De plus, ce véhicule";
    if(dieselVehicle.getFiltreAParticules()){
        cout << " dispose";
    } else {
        cout << " ne dispose pas";
    }
    cout << " d'un filtre à particules" << endl;
}
void displayTests2(){

    Vehicule vehicle(Point(5,6), "CC-987-JU", 50, 5.3);
    vehicle.afficher();

    GasVehicle gasVehicle(Point(25,3), "XY-358-PQ", 60, 6.8, 95);
    gasVehicle.afficher();

    DieselVehicle dieselVehicle(Point(2,10), "HD-888-ZY", 40, 5.5, true);
    dieselVehicle.afficher();
}
void consumptionTests(){
    DieselVehicle dieselVehicle(Point(1,1), "XY-358-PQ", 8, 5, false);
    dieselVehicle.afficher();
    cout << "*******" << endl;
    float traveletDist1 = dieselVehicle.moveTo(2, 2);
    std::cout << "Traveled distance: " << traveletDist1 << std::endl;
    dieselVehicle.afficher();
}