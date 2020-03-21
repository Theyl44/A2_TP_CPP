
#ifndef TP6_POINT_H
#define TP6_POINT_H

#include <iostream>

class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y);

    void setX(int x);
    void setY(int y);

    int getX();
    int getY();

    void afficherP();
};
#endif //TP6_POINT_H
