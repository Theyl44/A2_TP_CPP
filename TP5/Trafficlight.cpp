#include "Trafficlight.h"

Trafficlight :: Trafficlight(SignalColor initial_color){
    this->color = initial_color;
}

void Trafficlight ::  change(){
    if(this->get_color() == Red){
        this->color = Green;
    }
    else if(this->get_color() == Yellow){
        this->color = Red;
    }
    else if(this->get_color() == Green){
        this->color = Yellow;
    }
}
SignalColor Trafficlight :: get_color(){
    return this->color;
}
void Trafficlight :: print(){
    if(color == Red){
        cout << "+-------+"<<endl;
        cout << "|       |"<<endl;
        cout << "|  (R)  |"<<endl;
        cout << "|       |"<<endl;
        cout << "|  ( )  |"<<endl;
        cout << "|       |"<<endl;
        cout << "|  ( )  |"<<endl;
        cout << "|       |"<<endl;
        cout << "+-------+"<<endl;
    }
    if(color == Green){
        cout << "+-------+"<<endl;
        cout << "|       |"<<endl;
        cout << "|  ( )  |"<<endl;
        cout << "|       |"<<endl;
        cout << "|  ( )  |"<<endl;
        cout << "|       |"<<endl;
        cout << "|  (G)  |"<<endl;
        cout << "|       |"<<endl;
        cout << "+-------+"<<endl;
    }
    if(color == Yellow){
        cout << "+-------+"<<endl;
        cout << "|       |"<<endl;
        cout << "|  ( )  |"<<endl;
        cout << "|       |"<<endl;
        cout << "|  (Y)  |"<<endl;
        cout << "|       |"<<endl;
        cout << "|  ( )  |"<<endl;
        cout << "|       |"<<endl;
        cout << "+-------+"<<endl;
    }

}
void Trafficlight ::animeTraficLight(){
    int a = 0;
    while(a == 0){
        print();
        std::cin.get();
        change();
    }
}