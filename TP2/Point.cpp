#include "Point.h"
void Point:: setPoint(double x, double y){
    this->x = x;
    this->y = y;
}
double Point::  getX(){
    return x;
}
double Point::  getY(){
    return y;
}
Point  Point:: milieu(Point& P){
    Point sol;
    sol.setPoint((x+P.getX())/2 ,(y+P.getY())/2) ;
    return sol;
}
double  Point:: distance(Point& P){
    return (sqrt(((x-P.getX())*(x-P.getX())) + ((y-P.getY())*(y-P.getY()))));
}

void Point:: saisie(Point& p1,Point& p2){
    double x1,y1,x2,y2;
    std::cout <<"SAISIE DU POINT A"<<std::endl;
    std::cout <<"Tapez l'abscisse :"<<std::endl;
    std::cin >> x1;
    std::cout <<"Tapez l'ordonnée :"<<std::endl;
    std::cin >> y1;
    p1.setPoint(x1,y1);

    std::cout <<"SAISIE DU POINT B"<<std::endl;
    std::cout <<"Tapez l'abscisse :"<<std::endl;
    std::cin >> x2;
    std::cout <<"Tapez l'ordonnée :"<<std::endl;
    std::cin >> y2;
    p2.setPoint(x2,y2);

}
void Point:: result(Point& p1,Point& p2){
    std::cout <<"\nI LE MILIEU DE AB"<<std::endl;
    Point m1 = p1.milieu(p2);
    std::cout << "I = ("<<m1.getX()<<","<< m1.getY() <<")"<<std::endl;
    std::cout <<"la distance AB vaut ="<< p1.distance(p2)<< std::endl;

}
void Point1:: setPoint1(double x, double y){
    this->x = x;
    this->y = y;
}
double Point1:: getX1(){
    return x;
}
double Point1:: getY1(){
    return y;
}

Point1* Point1 ::milieu1(Point1* P){
    Point1* sol = new Point1;
    sol->setPoint1((x+P->getX1())/2 ,(y+P->getY1())/2) ;
    return sol;
}
double Point1:: distance1(Point1* P){
    return (sqrt(((x-P->getX1())*(x-P->getX1())) + ((y-P->getY1())*(y-P->getY1()))));
}

void Point1:: saisie1(Point1* p1,Point1* p2){
    double x1,y1,x2,y2;
    std::cout <<"SAISIE DU POINT A"<<std::endl;
    std::cout <<"Tapez l'abscisse :"<<std::endl;
    std::cin >> x1;
    std::cout <<"Tapez l'ordonnée :"<<std::endl;
    std::cin >> y1;
    p1->setPoint1(x1,y1);

    std::cout <<"SAISIE DU POINT B"<<std::endl;
    std::cout <<"Tapez l'abscisse :"<<std::endl;
    std::cin >> x2;
    std::cout <<"Tapez l'ordonnée :"<<std::endl;
    std::cin >> y2;
    p2->setPoint1(x2,y2);

}
void Point1:: result1(Point1* p1,Point1* p2){
    std::cout <<"\nI LE MILIEU DE AB"<<std::endl;
    Point1* m1 = new Point1;
    m1 = p1->milieu1(p2);
    std::cout << "I = ("<<m1->getX1()<<","<< m1->getY1() <<")"<<std::endl;
    std::cout <<"la distance AB vaut ="<< p1->distance1(p2)<< std::endl;
    delete(m1);
}


