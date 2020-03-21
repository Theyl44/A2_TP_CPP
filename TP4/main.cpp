#include "PGM.h"

using namespace std;

int main() {
    PGM image;
//    PGM image(10,10,0,255);
//    PGM image2(image);
//    image2.afficher();
//    image.initImage();
//    image.drawISEN();


//    image.readFile("lena_noisy.pgm");
//    image.thresholding(120,"chat_ascii.pgm");
    image.filterImage("chat_ascii.pgm",7);
    return 0;
}