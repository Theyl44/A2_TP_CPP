#include <iostream>
#include <cstdlib>

#ifndef TP2_TICTACTOE_H
#define TP2_TICTACTOE_H

enum Content {VIDE, ROND, CROIX, GAGANT};//gagnant a faire si j'ai le temps c'est long a faire et le rendu est pas si fou que ca mais j'aime bien ;)
using namespace std;
class TicTacToe {
private:
    int grille[3][3];
    bool placer_coup(int ligne, int colonne, Content c);
public :
    void init();
    //int len(int grille[3][3]); // pour calculer le nombre de lignes/colonnes de la grille
    bool placer_rond(int ligne, int colonne);
    bool placer_croix(int ligne, int colonne);
    void dessiner(int nbtours);
    bool tour(Content c);//return true si il y a un gagnant
    bool verif_de_fin_de_partie();//verifie les lignes/ colonnes/ digagonales
    void commencer_partie();
    bool grillefull();//si il n'y a pas de gagnant donc la grille est pleine


};

#endif //TP2_TICTACTOE_H
