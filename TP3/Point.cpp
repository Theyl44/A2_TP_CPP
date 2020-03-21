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
Point :: Point(){
    setPoint(0,0);
}
Point :: Point(Point const& p){
        x=p.x;
        y=p.y;
       //setPoint(p.getX(),p.getY());
}
Point :: Point(double x) : x(x), y(2*x){//liste d'initialisation

}
Point :: Point(double x, double y){
    setPoint(x,y);
}
void Point:: afficher(){
    std::cout <<"p=("<<x<<";"<<y<<")"<< std::endl;

}