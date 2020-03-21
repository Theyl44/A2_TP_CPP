//
// Created by Théo on 14/11/2019.
//

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
#include <cmath>

#ifndef TP4_PGM_H
#define TP4_PGM_H

class PGM{
private:
    int width;
    int height;
    int  maxvalue;
    int** data ;
    static int nbm;
public:
    //setter
    void setW(int width);
    void setH(int height);
    void setMaxV(int maxvalue);
    void setData(int** data);

    int getW();
    int getH();



    //methode
    PGM();
    PGM(int height, int width, int minpix, int maxpix);
    PGM(const PGM& p);
    ~PGM();
    void afficher();
    int** initImage();
    int getNbm();
    void deleteImage();
    int** createImage(int minpix, int maxpix);
    void drawrect(int x1, int y1, int x2, int y2, int val);
    void drawline(int x1, int x2, int line, int val);
    void drawcross(int x , int y , int val);

    void drawISEN();
    void readFile(char* filename);
    void writeFile(char* filename);
    void thresholding(int th, char* filename);
    void filterImage(char* filename, int k);
    int mediane(int i , int j, int k);
    void orderTab(int size,int* tab);

};
#endif //TP4_PGM_H
