#include <iostream>
using namespace std;

#ifndef TP5_TRAFFICLIGHT_H
#define TP5_TRAFFICLIGHT_H

enum SignalColor { Red, Green, Yellow };

class Trafficlight {
private:
    SignalColor color;
public:
    Trafficlight(SignalColor initial_color = Red);
    void change();
    SignalColor get_color();
    void print();
    void animeTraficLight();
};
#endif //TP5_TRAFFICLIGHT_H
