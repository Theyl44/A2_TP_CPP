#include "Point.h"

void Point ::  setX(int x){
    this->x = x;
}
void Point ::  setY(int y){
    this->y = y;
}

int Point :: getX(){
    return x;
}
int Point :: getY(){
    return y;
}
Point :: Point(int x, int y){
    setY(y);
    setX(x);
}
void Point :: afficherP(){
    std::cout <<"("<<x<<","<<y<<")";
}
