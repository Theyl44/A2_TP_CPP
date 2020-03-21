//
// Created by Théo on 1/23/2020.
//

#include "StationMeteo.h"

void StationMeteo :: addObservateur(shared_ptr<Observateur> p){
    this->Observateurs.push_back(p);
}
void StationMeteo :: notif(){
    cout<<"La Nouvelle valeur de température est "<< this->temperature <<endl;
}
void StationMeteo :: setTemperateur(float t){
   if(t != this->temperature){
        this->temperature = t ;
        this->notif();
    }
}
StationMeteo :: StationMeteo(float t){
    this->temperature = t;
}