#include "Rational.h"
Rational :: Rational(){
    setN(1);
    setD(1);
}
Rational :: Rational(int n, int d){
    setN(n);
    setD(d);
}
Rational :: Rational(Rational const& p){
    setD(p.denominator);
    setN(p.numerator);
}
void Rational :: setN(int N){
    numerator = N;
}
void Rational::setD(int D) {
    if(D !=0) {
        denominator = D;
    } else{
        cout << "error";
    }
}

int Rational :: getN(){
    return numerator;
}
int Rational :: getD(){
    return denominator;
}
int Rational :: pgcd(int a, int b){
    int r;
    while (b != 0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int Rational :: ppcm(int X, int Y){
    int A=X;
    int B=Y;
    while (A!=B)
    {
        while (A>B) B=B+Y;
        while (A<B) A=A+X;
    }
    return A;
}
void Rational :: afficher(){
    cout << numerator << " / " << denominator ;
}
Rational Rational :: reduce(){
    Rational result;
    int r = pgcd(getN(), getD());

    result.setD(getD()/r);
    result.setN(getN()/r);
    return result;
}
bool Rational ::equFract(Rational r1){
    Rational p1 = this->reduce();
    Rational p2 = r1.reduce();
    if(p1.getD() == p2.getD() && p1.getN() == p2.getN()){
        return true;
    }
    else{
        return false;
    }
}
Rational Rational:: sumFract(Rational r1){
    Rational p1;
    p1.setD(this->getD());
    p1.setN(this->getN());

    Rational p2;
    p2.setD(r1.getD());
    p2.setN(r1.getN());

    p1.afficher();
    cout << " + ";
    p2.afficher();
    cout << " = ";

    if(this->getD() == r1.getD()){
        p1.setN(r1.getN()+this->getN());
        p1.setD(r1.getD());
        p1.reduce().afficher();
        cout << "\n";
        return p1.reduce();
    }else{
        p1.setN(p1.getN()*p2.getD());
        p1.setD(p1.getD()*p2.getD());


        p2.setN(p2.getN()*this->getD());
        p2.setD(p1.getD());

        return p1.sumFract(p2).reduce();
    }
}
Rational Rational :: prodFract(Rational r1){
    Rational result;
    this->afficher();
    cout <<" * ";
    r1.afficher();
    cout << " = ";
    result.setN(this->getN()*r1.getN());
    result.setD(this->getD()*r1.getD());
    result.reduce().afficher();
    return result.reduce();

}