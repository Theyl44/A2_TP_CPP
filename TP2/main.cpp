#include <iostream>
#include <cstdlib>
#include "Equation.h"
#include "Point.h"
#include "tictactoe.h"

double randomDouble(double min, double max);
Point* createRandomPath(int nbSteps, double minX, double maxX, double minY, double maxY);
void showRandomPath(Point* pathPoints, int nbSteps);
double followPath(Point* point, Point* path, int nbSteps);
using namespace std;
int main() {

//EXO 1
//    Equation S;
//    double a,b,c;
//    cout << "A ="<<endl;
//    cin >> a;
//    cout << "B ="<<endl;
//    cin >> b;
//    cout << "C ="<<endl;
//    cin >> c;
//    S.setA(a);
//    S.setB(b);
//    S.setC(c);
//    double test = S.image(2);
//    cout <<"test est = "<< test<<endl;

//    S.result();
//EXO 2 POINT
//    Point p1;
//    Point p2;


//EXO 2 PRT 4 allocation dynamique
//    Point1* p1 = new Point1;
//    Point1* p2 = new Point1;
//    p1->setPoint1(4,12);
//    p2->setPoint1(3,3);
//    double distance = p1->distance1(p2);
//    Point1* p3 = new Point1;
//    p3 = p1->milieu1(p2);
//    cout << "p3 = ("<<p3->getX1()<<","<< p3->getY1() <<")"<< endl;
//    cout <<"la distance = "<<distance<<endl;
//    delete(p1);
//    delete(p2);
//EXO 2 PRT 4 4 chemin de point
//    srand( time(NULL) );
//    int nbrcase = 10;
//    Point* p1 = new Point;
//    Point* tab = createRandomPath(nbrcase,0,10,0,10);
//    showRandomPath(tab,nbrcase);
//
//    double taille = followPath(p1,tab,nbrcase);
//    cout <<"la distance du chemin vaut = "<<taille << endl;
//    delete tab;

//EXO SUPPLEMENTAIRE TICTACTOE
    TicTacToe GAME;
    GAME.commencer_partie();
    return 0;
}

double randomDouble(double min, double max) {
    return (rand() / ((double)RAND_MAX)) * (max-min) + min;
}
Point* createRandomPath(int nbSteps, double minX, double maxX, double minY, double maxY){
    Point* tabpoints = new Point[nbSteps];// création de nbSteps objet
    for(int i = 0 ; i < nbSteps ; i++){
        tabpoints[i].setPoint(randomDouble(minX,maxX),randomDouble(minY,maxY));
    }
    return tabpoints;
}
void showRandomPath(Point* pathPoints, int nbSteps){
    for(int i = 0 ; i < nbSteps ; i++){
        cout <<"point #"<<i+1<<" = ("<<pathPoints[i].getX()<<" , "<<pathPoints[i].getY()<<")"<<endl;
    }
}
double followPath(Point* point, Point* path, int nbSteps){
    double taille = 0 ;
    point->setPoint(path[0].getX(),path[0].getY());
    for(int i = 1; i<nbSteps;i++){
        taille = taille + point->distance(path[i+1]);
        point->setPoint(path[i].getX(),path[i].getY());
    }
    return taille;
}
