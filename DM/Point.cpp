#include "Point.h"

//PARTIE 1

double Point_part1:: distance(Point_part1 P){
    return sqrt(pow((x-P.x), 2)+pow((y-P.y),2));
}
Point_part1 Point_part1:: milieu(Point_part1 P){
    Point_part1 I;
    I.x =(x+P.x)/2;
    I.y =(y+P.y)/2;
    return I;
}
void Point_part1:: saisir(){
    std::cout <<"Tapez l'abscisse :"<<std::endl;
    std::cin >> x;
    std::cout <<"Tapez l'ordonnée :"<<std::endl;
    std::cin >> y;
}
void Point_part1::  afficher(){
    std :: cout << "p = (" << x << "," << y << ")"<< std ::endl;
}

//PARTIE  3

void Point_part3 :: setX(double x){
    this->x = x;
}
void Point_part3 :: setY(double y){
    this->y = y ;
}
double Point_part3 ::getX(){
    return x;
}
double Point_part3 ::getY(){
    return y;
}
void Point_part3 :: saisir(){
    double x1,y1;
    std::cout <<"Tapez l'abscisse :"<<std::endl;
    std::cin >> x1;
    std::cout <<"Tapez l'ordonnée :"<<std::endl;
    std::cin >> y1;
    setX(x1);
    setY(y1);
}
void Point_part3 :: afficher(){
    std :: cout << "p = (" << getX() << "," << getX() << ")"<< std ::endl;
}

//PARTIE 4

void Point_part4::setX(double x){
    this->x = x;
}
void Point_part4::setY(double y){
    this->y = y;
}
double Point_part4:: getX(){
    return x;
}
double Point_part4::getY(){
    return y;
}
Point_part4* Point_part4::milieu(Point_part4* P){
    Point_part4* sol = new Point_part4;
    sol->setX((x+P->getX())/2);
    sol->setY((y+P->getY())/2);
    return sol;
}
double Point_part4::distance( Point_part4* P){
    return (sqrt(((x-P->getX())*(x-P->getX())) + ((y-P->getY())*(y-P->getY()))));
}

void Point_part4:: saisir(){
    double x1,y1;
    std::cout <<"SAISIE DU POINT A"<<std::endl;
    std::cout <<"Tapez l'abscisse :"<<std::endl;
    std::cin >> x1;
    std::cout <<"Tapez l'ordonnée :"<<std::endl;
    std::cin >> y1;
    setX(x1);
    setY(y1);
}
void Point_part4 :: afficher(){
    std :: cout << "p = (" << x << "," << y << ")"<< std ::endl;
}