#include "Vehicule.h"

Vehicule :: Vehicule() : position(0,0){
    // 10 est la taille max des caractères d'une plaque
    std::cout << "\tCrea Vehicule()"<<std::endl;
    identifier = new char[10*sizeof(char)];
    strcpy(identifier,"");
}

Vehicule ::Vehicule(Point p,char* id, float carburant , float consommation) : position(p.getX(),p.getY()) {
    std::cout << "\tCrea Vehicule(p,id)"<<std::endl;
    identifier = new char[10*sizeof(char)];
    strcpy(identifier,id);
    this->consommation = consommation;
    this->carburant = carburant;
}
Vehicule :: ~Vehicule(){//probleme quand il y a une copie j'ai l'impression qu'il veux le delete 2 fois nsm
    std::cout << "\tDestruction du Vehicule()"<<std::endl;
        delete[] identifier;
}
Vehicule ::Vehicule(Vehicule const & v) :position(v.position) {
    std::cout << "\tCrea Vehicule(const& )"<<std::endl;
    identifier = new char[10* sizeof(char)];
    strcpy(identifier, v.identifier);
    this->carburant = v.carburant;
    this->consommation = v.consommation;

}
void Vehicule ::afficher(){
    std::cout<<"[";
    std:: cout << getId();
    std::cout<<"] ";
    std::cout<<"position : ";
    getPosition().afficherP();
    std::cout<<", consumption: "<< this->consommation<<", fuel left: "<< this->carburant<< std::endl;

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

    float distanceAB = distance(p.getX(),p.getY(),this->position.getX(),this->position.getY());
    float carburantAB = distanceAB * this->consommation;
    std::cout <<"distance AB = "<< distanceAB << " carburant AB = " << carburantAB << std::endl;
    if(carburantAB <= this->carburant){//je peux atteindre la distance demandé
        this->carburant = carburant - carburantAB;
        this->setPosition(p);
        return distanceAB;
    }else{// je ne peux pas allé jusqu'au bout mais inch on se rapproche
        float distanceAM = this->carburant* distanceAB / carburantAB;
        float r = distanceAM / distanceAB;
        float xx = (1-r)*x + r*position.getX();
        float yy = (1-r)*y + r*position.getY();


        std::cout <<"distanceAM =" << distanceAM<<std::endl;

        this->setPosition(Point(x,y));
        this->setCarburant(0);
        return distanceAM;
    }

}
void Vehicule :: reset(){
    this->position.setX(0);
    this->position.setY(0);
}

void Vehicule :: setConsommation(float d){
    this->consommation = d;
}
void Vehicule :: setCarburant(float d){
    this->carburant = d;
}
float Vehicule ::  getConsommation(){
    return consommation;
}
float Vehicule :: getCarburant(){
    return carburant;
}

//---------------------------------------
//DIESEL VEHICULE
//---------------------------------------

DieselVehicle :: DieselVehicle(Point p, char* name, float carburant, float consommation, bool b){
    std::cout << "\tDieselVehicule()"<<std::endl;
    this->filtreAParticules = b;
    this->setId(name);
    this->setPosition(p);
    this->setCarburant(carburant);
    this->setConsommation(consommation);
}
bool DieselVehicle :: getFiltreAParticules(){
    return this->filtreAParticules;
}
void DieselVehicle :: setFiltreAParticules(bool b){
    filtreAParticules = b;
}
void DieselVehicle :: afficher(){
    std::cout<<"[";
    std:: cout << getId();
    std::cout<<"] ";
    std::cout<<"position : ";
    getPosition().afficherP();
    std::cout<<", consumption: "<< this->consommation<<", fuel left: "<< this->carburant ;

    if(this->getFiltreAParticules()){
        std::cout << ", true"<<std:: endl;
    } else {
        std::cout << ", false" << std:: endl;
    }
}

//---------------------------------------
//GAS VEHICULE
//---------------------------------------

GasVehicle :: GasVehicle(Point p, char* name, float carburant, float consommation,int octaneRate, bool b){
    std::cout << "\tCrea GasVehicule()"<<std::endl;
    this->filtreAParticules = b;
    this->octaneRate = octaneRate;
    this->setPosition(p);
    this->setId(name);
    this->setCarburant(carburant);
    this->setConsommation(consommation);
}
bool GasVehicle::getFiltreAParticules(){
    return this->filtreAParticules;
}
void GasVehicle::setFiltreAPArticules(bool b){
    this->filtreAParticules = b;
}
int GasVehicle::getOctaneRate(){
    return this->octaneRate;
}
void GasVehicle:: setOctaneRate(int octanerate){
    this->octaneRate = octanerate;
}
void GasVehicle :: afficher(){
    std::cout<<"[";
    std:: cout << getId();
    std::cout<<"] ";
    std::cout<<"position : ";
    getPosition().afficherP();
    std::cout<<", consumption: "<< this->consommation<<", fuel left: "<< this->carburant<< ", octane rating: " << this->octaneRate ;

    if(this->getFiltreAParticules()){
        std::cout << ", true"<<std:: endl;
    } else {
        std::cout << ", false" << std:: endl;
    }
}
