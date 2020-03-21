#include <iostream>

enum Content {VIDE, ROND, CROIX, GAGANT};
//on affiche le coup qui gagne quand on a un vaiqueur
using namespace std;

#ifndef DM_TICTACTOE_H
#define DM_TICTACTOE_H

class TicTacToe {
private:
    int grille[3][3];
    bool placer_coup(int ligne, int colonne, Content c);
public :
    void init();
    //int len(int grille[3][3]); // pour calculer le nombre de lignes/colonnes de la grille
    bool placer_rond(int ligne, int colonne);
    bool placer_croix(int ligne, int colonne);
    void dessiner();
    bool tour(Content c);//return true si il y a un gagnant
    bool verif_de_fin_de_partie();//verifie les lignes/ colonnes/ digagonales
    void commencer_partie();
    bool grillefull();//si il n'y a pas de gagnant donc la grille est pleine


};
#endif //DM_TICTACTOE_H
