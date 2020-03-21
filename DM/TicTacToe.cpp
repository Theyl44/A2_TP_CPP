#include "TicTacToe.h"

bool TicTacToe:: grillefull(){
    for(int i = 0 ; i < 3 ; i ++){
        for(int j = 0 ; j < 3 ; j++){
            if(grille[i][j]==VIDE){
                return false;
            }
        }
    }
    return true;
}
void TicTacToe:: init(){
    for(int i=0;i < 3 ; i++){
        for(int j=0;j < 3;j++){
            grille[i][j] = VIDE;
        }
    }
}
bool TicTacToe:: placer_rond(int ligne, int colonne){
    if(ligne<3 && ligne >= 0 && colonne<3 && colonne >= 0){
        if( grille[ligne][colonne] == VIDE) {
            grille[ligne][colonne] = ROND;
            return true;
        }
        return false;//ne rien faire si qqln a deja jouer a cette place
    }
    return false;
}
bool TicTacToe:: placer_croix(int ligne, int colonne){
    if(ligne< 3 && ligne >= 0 && colonne<3 && colonne >= 0){
        if( grille[ligne][colonne] == VIDE) {
            grille[ligne][colonne] = CROIX;
            return true;
        }
        return false;//ne rien faire si qqln a deja jouer a cette place
    }
    return false;
}
void TicTacToe:: dessiner(){
    cout<<"---------------";
    cout<<endl;
    for(int i=0;i < 3 ; i++){
        for(int j=0;j < 3;j++){
            switch(grille[i][j]) {
                case VIDE:
                    cout << "|   |";
                    break;
                case ROND:
                    cout << "| O |";
                    break;
                case CROIX:
                    cout << "| X |";
                    break;
                case GAGANT:
                    cout << "| $ |";
                    break;
            }

        }
        cout<<endl;
        cout<<"---------------";
        cout<<endl;
    }

}
bool TicTacToe::placer_coup(int ligne, int colonne, Content c){
    bool verif;

    switch (c) {
        case CROIX:
            verif = placer_croix(ligne, colonne);
            break;
        case ROND:
            verif = placer_rond(ligne, colonne);
    }

    return verif;
}
bool TicTacToe:: tour(Content c){
    int ligne,colonne;
    bool verif = false;
    while(!verif) {
        if(c == ROND){
            cout << endl;
            cout<<"A ROND DE JOUER"<<endl;
        }
        if(c == CROIX){
            cout << endl;
            cout<<"A CROIX DE JOUER"<<endl;
        }
        cout << "entrez une ligne / colonne (entre 0 et 2)" << endl;
        cin >> ligne;
        cin >> colonne;
        verif = placer_coup(ligne, colonne, c);
        if(grillefull()){//si la grille est pleien le jeux s'arrete ...
            if(verif_de_fin_de_partie()){
                cout<<"----------------------------------"<<endl;
                cout<<"FELICITATION NOUS AVONS UN GAGNANT"<<endl;
                cout<<"----------------------------------"<<endl;
                dessiner();
            }
            dessiner();
            cout <<"game over"<<endl;
            return false;
        }
        if(verif_de_fin_de_partie()){
            cout<<"----------------------------------"<<endl;
            cout<<"FELICITATION NOUS AVONS UN GAGNANT"<<endl;
            cout<<"----------------------------------"<<endl;
            dessiner();
            return false;
        }
    }
    return true;

}
void TicTacToe :: commencer_partie(){
    init();
    bool verif = false;//pour savoir qui commence
    bool jeux_en_cour = true;
    int joueur;
    while(!verif) {
        cout << "Qui commence ROND ou CROIX ? (croix = 0, rond = 1)" << endl;//petit plus ;)
        cin >> joueur;
        if(joueur == 1 || joueur == 0){
            verif = true;
        }
    }
    dessiner();
    for(int i = 1; i < 9 ; i++){
        if(jeux_en_cour == true) {
            if (joueur == 0) {
                jeux_en_cour = tour(CROIX);
                if(jeux_en_cour) {
                    dessiner();
                    joueur = 1;
                }
            }
            if (joueur == 1) {
                jeux_en_cour = tour(ROND);
                if(jeux_en_cour) {
                    dessiner();
                    joueur = 0;
                }
            }
        }
    }
}
bool TicTacToe:: verif_de_fin_de_partie(){//on test toute les combi si on a un gagnant
    //si rond gagne sur une ligne
    if(grille[0][0]==ROND && grille[0][1]==ROND && grille[0][2]==ROND){
        grille[0][0]=GAGANT;
        grille[0][1]=GAGANT;
        grille[0][2]=GAGANT;
        return true;
    }
    if(grille[1][0]==ROND && grille[1][1]==ROND && grille[1][2]==ROND){
        grille[1][0]=GAGANT;
        grille[1][1]=GAGANT;
        grille[1][2]=GAGANT;
        return true;
    }
    if(grille[2][0]==ROND && grille[2][1]==ROND && grille[2][2]==ROND){
        grille[2][0]=GAGANT;
        grille[2][1]=GAGANT;
        grille[2][2]=GAGANT;
        return true;
    }
    //si croix gagne sur une ligne
    if(grille[0][0]==CROIX && grille[0][1]==CROIX && grille[0][2]==CROIX){
        grille[0][0]=GAGANT;
        grille[0][1]=GAGANT;
        grille[0][2]=GAGANT;
        return true;
    }
    if(grille[1][0]==CROIX && grille[1][1]==CROIX && grille[1][2]==CROIX){
        grille[1][0]=GAGANT;
        grille[1][1]=GAGANT;
        grille[1][2]=GAGANT;
        return true;
    }
    if(grille[2][0]==CROIX && grille[2][1]==CROIX && grille[2][2]==CROIX){
        grille[2][0]=GAGANT;
        grille[2][1]=GAGANT;
        grille[2][2]=GAGANT;
        return true;
    }

    //si rond gagne sur un colonne
    if(grille[0][0]==ROND && grille[1][0]==ROND && grille[2][0]==ROND){
        grille[0][0]=GAGANT;
        grille[1][0]=GAGANT;
        grille[2][0]=GAGANT;
        return true;
    }
    if(grille[0][1]==ROND && grille[1][1]==ROND && grille[2][1]==ROND){
        grille[0][1]=GAGANT;
        grille[1][1]=GAGANT;
        grille[2][1]=GAGANT;
        return true;
    }
    if(grille[0][2]==ROND && grille[1][2]==ROND && grille[2][2]==ROND){
        grille[0][2]=GAGANT;
        grille[1][2]=GAGANT;
        grille[2][2]=GAGANT;
        return true;
    }
    //si croix gagne sur une colonne
    if(grille[0][0]==CROIX && grille[1][0]==CROIX && grille[2][0]==CROIX){
        grille[0][0]=GAGANT;
        grille[1][0]=GAGANT;
        grille[2][0]=GAGANT;
        return true;
    }
    if(grille[0][1]==CROIX && grille[1][1]==CROIX && grille[2][1]==CROIX){
        grille[0][1]=GAGANT;
        grille[1][1]=GAGANT;
        grille[2][2]=GAGANT;
        return true;
    }
    if(grille[0][2]==CROIX && grille[1][2]==CROIX && grille[2][2]==CROIX){
        grille[0][2]=GAGANT;
        grille[1][2]=GAGANT;
        grille[2][2]=GAGANT;
        return true;
    }

    //si rond gagne sur diagonale
    if(grille[0][0]==ROND && grille[1][1]==ROND && grille[2][2]==ROND){
        grille[0][0]=GAGANT;
        grille[1][1]=GAGANT;
        grille[2][2]=GAGANT;
        return true;
    }
    if(grille[2][0]==ROND && grille[1][1]==ROND && grille[0][2]==ROND){
        grille[2][0]=GAGANT;
        grille[1][1]=GAGANT;
        grille[0][2]=GAGANT;
        return true;
    }
    //si croix  gagne sur diagonale
    if(grille[0][0]==CROIX && grille[1][1]==CROIX && grille[2][2]==CROIX){
        grille[0][0]=GAGANT;
        grille[1][1]=GAGANT;
        grille[2][2]=GAGANT;
        return true;
    }
    if(grille[2][0]==CROIX && grille[1][1]==CROIX && grille[0][2]==CROIX){
        grille[2][0]=GAGANT;
        grille[1][1]=GAGANT;
        grille[0][2]=GAGANT;
        return true;
    }
    return false;
}
