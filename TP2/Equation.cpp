#include "Equation.h"

double Equation::image(double x){
    return a*x*x+b*x+c;
}
void Equation:: result(){
    double sol1,sol2;
    float delta =(b*b)-4*a*c;
    if(delta==0){
        sol1 = -b/2*a;
        std::cout<<"1 solution : sol 1 = "<<sol1;
    }
    if(delta>0){
        sol1 = (-b+sqrt(delta))/(2*a);
        sol2 = (-b-sqrt(delta))/(2*a);
        std::cout<<"2 solutions : sol 1 = "<<sol2<<" sol2 ="<< sol1;

    }
    if(delta<0){
        std::cout<<"il n'y a pas de solution dans R";
    }
}
void Equation ::setA(double a){
    if(this->a!=0){
      this->a=a;
    }else {
        std::cout << "error" << std::endl;
    }
}
void Equation ::setB(double b){
    this->b =b;
}
void Equation ::setC(double c){
    this->c =c;
}
double Equation ::getA(){
    return a;
}
double Equation ::getB(){
    return b;
}
double Equation ::getC(){
    return c;
}
