#include "Point.h"
#include "TicTacToe.h"

void test_part1();
void test_part3();
void test_part4();
void test_part5();

double randomDouble(double min, double max);
Point_part4* createRandomPath(int nbSteps, double minX, double maxX, double minY, double maxY);
void showRandomPath(Point_part4* pathPoints, int nbSteps);
double followPath(Point_part4* point, Point_part4* path, int nbSteps);

using namespace std;
int main() {
    //EXO 2
    //test_part1();
    //test_part3();
    //test_part4();
    //test_part5();

    //EXO 3
    TicTacToe GAME;
    GAME.commencer_partie();

    return 0;
}
double randomDouble(double min, double max){
    return (rand() / ((double)RAND_MAX)) * (max-min) + min;
}
Point_part4* createRandomPath(int nbSteps, double minX, double maxX, double minY, double maxY){
    Point_part4* tabpoints = new Point_part4[nbSteps];// création de nbSteps objet

    for(int i = 0 ; i < nbSteps ; i++){

        tabpoints[i].setX(randomDouble(minX,maxX));
        tabpoints[i].setY(randomDouble(minY,maxY));
    }
    return tabpoints;
}
void showRandomPath(Point_part4* pathPoints, int nbSteps){
    cout << "Votre chemine est : "<<endl;
    for(int i = 0 ; i < nbSteps ; i++){
        cout <<"point #"<<i+1<<" = ("<<pathPoints[i].getX()<<" , "<<pathPoints[i].getY()<<")"<<endl;
    }
}
double followPath(Point_part4* point, Point_part4* path, int nbSteps){
    Point_part4* nextpoint = new Point_part4;
    double taille = 0 ;
    point->setX(path[0].getX());
    point->setY(path[0].getY());

    for(int i = 1; i<nbSteps;i++){
        nextpoint->setX(path[i].getX());
        nextpoint->setY(path[i].getX());
        taille = taille + point->distance(nextpoint);
        point->setX(path[i].getX());
        point->setY(path[i].getY());
    }
    return taille;
}
void test_part1(){
    //PARTIE 1
    Point_part1 p1;
    cout << "**SAISIE DU POINT A**"<< endl;
    p1.saisir();
    p1.afficher();
    cout << "**SAISIE DU POINT B**"<< endl;
    Point_part1 p2;
    p2.saisir();
    p2.afficher();

    Point_part1 I1 = p1.milieu(p2);
    cout << "\n**MILIEU DE AB**"<< endl;
    I1.afficher();
    double distance = p1.distance(p2);
    cout << "distance = " << distance << endl;

}
void test_part3(){
    //PARTIE 3
    Point_part3 p3;
    cout << "**SAISIE DU POINT A**" << endl;
    p3.saisir();
    p3.afficher();
    Point_part3 p4;
    cout << "**SAISIE DU POINT B**" << endl;
    p4.saisir();
    p4.afficher();

}
void test_part4(){
    //PARTIE 4
    Point_part4* p1 = new Point_part4;
    Point_part4* p2 = new Point_part4;
    cout << "**SAISIE DU POINT A**"<< endl;
    p1->saisir();
    p1->afficher();
    cout << "**SAISIE DU POINT B**"<< endl;
    p2->saisir();
    p2->afficher();

    double distance = p1->distance(p2);
    Point_part4* p3 = new Point_part4;
    cout << "\n**MILIEU DE AB**"<< endl;
    p3 = p1->milieu(p2);
    p3->afficher();
    cout <<"la distance = "<<distance<<endl;

    delete(p1);
    delete(p2);
    delete(p3);

}void test_part5(){
    srand( time(NULL) );
    int nbrpoints;
    double minX,minY,maxX,maxY;
    bool verif = true;

    cout << "combien de point voulez vous ? "<<endl;
    cin >> nbrpoints;

    while(verif){
        cout << "quel interval voulez vous en X (min et max) ? "<< endl;
        cin >> minX;
        cin >> maxX;
        if(minX <= maxX){//pour ne pas rentrer n'importe quoi
            verif = false;
        }
    }
    while(!verif){
        cout << "quel interval voulez vous en Y (min et max) ? "<< endl;
        cin >> minY;
        cin >> maxY;
        if(minY <= maxY){//pour ne pas rentrer n'importe quoi
            verif = true;
        }
    }
    int nbrcase = nbrpoints;
    Point_part4* p1 = new Point_part4;
    Point_part4* tab = createRandomPath(nbrcase,0,10,0,10);

    showRandomPath(tab,nbrcase);
    double taille = followPath(p1,tab,nbrcase);
    cout <<"\nla distance du chemin vaut = "<<taille << endl;
     delete tab;
}
