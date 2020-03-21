
    #include <iostream>
    #include <cmath>

#ifndef TP2_POINT_H
#define TP2_POINT_H

class Point{
private:
    double x;
    double y;

public:
    void setPoint(double x, double y);
    double getX();
    double getY();

    Point milieu(Point& P);
    double distance(Point& P);

    void saisie(Point& p1,Point& p2);
    void result(Point& p1,Point& p2);
};

class Point1{
private:
    double x;
    double y;
public:
    void setPoint1(double x, double y);
    double getX1();
    double getY1();

    Point1* milieu1(Point1* P);
    double distance1(Point1* P);

    void saisie1(Point1* p1,Point1* p2);
    void result1(Point1* p1,Point1* p2);

};
#endif //TP2_POINT_H
