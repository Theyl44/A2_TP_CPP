#include "Point.h"
#include "Vehicule.h"

using namespace std;

void vehiculeIdTest();
void vehiculeIdTest2();
void vehiculeCopyTest();
void vehicleMoveTests();

int main() {
//    Point p(2,3);
//    Vehicule v1(p,"AX 1111 DE");
//    Vehicule v2(v1);
//    v2.afficherV();

//    Point p1(1,1);
//    Point p2(3,3);
//    Vehicule v1(p1,"AX 1111 DE");
//    Vehicule v2(p2, "DE 2322 AX");
//    v1.afficherV();
//    v2.afficherV();
//    v1.moveTo(v2);

//TEST DU PROF
    vehiculeIdTest();
//    vehiculeIdTest2();
//    vehiculeCopyTest();
//    vehicleMoveTests();
    return 0;
}
void vehiculeIdTest() {
    Point position(0,10);
    char identifier[] = "ML-888-VK";
    Vehicule vehicle(position,identifier);
    vehicle.afficherV(); // affichage 1
    char * retrieveId = vehicle.getId();
    retrieveId[0] = 'X';//car read only
    vehicle.afficherV(); // affichage 2
}
void vehiculeIdTest2() {
    Point position(0,10);
    char identifier[] = "ML-888-VK";
    Vehicule vehicle(position,identifier);
    vehicle.afficherV(); // affichage 1
    identifier[0] = 'X';
    vehicle.afficherV(); // affichage 2
}
void vehiculeCopyTest(){

    Vehicule v1(Point(0,0),"JK-857-FA");
    Vehicule v2 = v1;
    v1.setId("XXX");
    v1.afficherV();
    v2.afficherV();
}
void vehicleMoveTests(){
    Vehicule v1(Point(0,0),"JK-857-FA");
    Vehicule v2(Point(0,10),"ML-888-VK");

    Point p = v1.getPosition();
    float distance = 0;

    distance = v1.moveTo(v2);
    std::cout << "distance : " << distance << std::endl; // affichage 1
    v1.afficherV(); // affichage 2

    p.setY(50);
    std::cout << p.getY()<<endl;
    v1.afficherV(); // affichage 3
    distance = v1.moveTo(p);

    std::cout << "distance : " << distance << std::endl; // affichage 4
    v1.afficherV(); // affichage 5
    distance = v1.moveTo(0, 80);

    std::cout << "distance : " << distance << std::endl; // affichage 6
    v1.afficherV(); // affichage 7
    v2.afficherV(); // affichage 8
}

