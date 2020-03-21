#include "Vehicule.h"

Vehicule :: Vehicule() : position(0,0){
    // 10 est la taille max des caractères d'une plaque
    identifier = new char[10*sizeof(char)];
    strcpy(identifier,"");
}

Vehicule ::Vehicule(Point p,char* id) : position(p.getX(),p.getY()) {
    identifier = new char[10*sizeof(char)];
    strcpy(identifier,id);
}
Vehicule :: ~Vehicule(){//probleme quand il y a une copie j'ai l'impression qu'il veux le delete 2 fois nsm
        delete[] identifier;
}
Vehicule ::Vehicule(Vehicule const & v) :position(v.position) {
    identifier = new char[10* sizeof(char)];
    strcpy(identifier, v.identifier);

}
void Vehicule ::afficherV(){
    std::cout<<"[";
    std:: cout << this->identifier;
    std::cout<<"] ";
    std::cout<<"position : ";
    this->position.afficherP();
}
void Vehicule ::setId(char* id){
    strcpy(identifier,id);

}
void Vehicule ::setPosition(Point p){
    this->position.setX(p.getX());
    this->position.setY(p.getY());
}

Point Vehicule ::getPosition(){
    return this->position;
}
char* Vehicule :: getId(){
  char* id = this->identifier;
    return id;
}

float distance(int x1,int y1, int x2,int y2) {
    return (float)sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
}
float Vehicule :: moveTo(Point p){
    float result=distance(p.getX(),p.getY(),this->position.getX(),this->position.getY());
    this->setPosition(p);
//    std::cout<<"distance = "<< result << std::endl;
    return result;
}
float Vehicule :: moveTo(Vehicule& v){
    float result = distance(v.position.getX(),v.position.getY(),this->position.getX(),this->position.getY());
    this->setPosition(v.position);
//    std::cout<<"distance = "<< result << std::endl;
    return result;
}
float Vehicule :: moveTo(int x, int y){
    Point p(x,y);
    float result = distance(p.getX(),p.getY(),this->position.getX(),this->position.getY());
    this->setPosition(p);
//    std::cout<<"distance = "<< result << std::endl;
    return result;
}
void Vehicule :: reset(){
    this->position.setX(0);
    this->position.setY(0);
}