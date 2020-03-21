#include <sstream>
#include "PGM.h"
//setter
void PGM :: setW(int width){
    this->width = width;
}
void PGM :: setH(int height){
    this->height = height;
}
void PGM ::setMaxV(int maxvalue){
    this->maxvalue = maxvalue;
}
void PGM ::  setData(int** data){
    this->data = data;
}

//methode
void PGM ::  afficher(){
    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ;j ++){
            std::cout << data[i][j]<<"    ";
        }
        std::cout << "\n";
    }
}
int** PGM :: initImage(){
    setH(height);
    setW(width);
    data = new int*[height];

    for(int i = 0 ; i < height ; i++){//dans chq case de la largeur height on crééer un tab de longeur width
       data[i] = new int[width];
    }
    return data;
}
void PGM ::  deleteImage(){
    for(int i = 0 ; i < height ; i++){
        if(data != NULL) {
            delete[] data[i];
        }
    }
    if(data != NULL) {
        delete[] data;
    }
}
int** PGM :: createImage(int minpix, int maxpix){
    int** tab = initImage();
    srand( time(NULL) );
    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ;j ++) {
         data[i][j] = rand() % (maxpix-minpix) + minpix;
        }
    }
    return tab;
}

PGM :: PGM(){
    setW(10);
    setH(10);
    setMaxV(0);
    nbm++;
    initImage();
}
PGM::PGM(int height, int width,int minpix, int maxpix){
    setW(width);
    setH(height);
    setMaxV(maxpix);
    nbm++;
    createImage(minpix,maxpix);
}
PGM :: ~PGM(){
    deleteImage();
    nbm--;
}
PGM :: PGM (PGM const& p){
    setH(p.height);
    setW(p.width);
    setMaxV(p.maxvalue);
    data = initImage();
    for(int i = 0 ; i < height ; i ++){
        for (int j = 0 ; j < width ; j++){
            data[i][j] = p.data[i][j];
        }
    }
    nbm++;
}
void PGM:: writeFile(char* filename) {
    ofstream newfile;
    newfile.open(filename);
    newfile << "P2" << endl;
    newfile << width << " " << height << endl;
    newfile << maxvalue << endl;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            newfile << data[i][j] << " ";
        }
        newfile << "\n";
    }
    newfile.close();
}
int PGM ::  getNbm(){
    return nbm;
}
void PGM :: drawrect(int x1, int y1, int x2, int y2, int val){
    for(int i = x1 ; i < x2 ; i++){
        for(int j = y1 ; j < y2 ; j++){
            data[i][j] = val;
        }
    }
}
void PGM :: drawline(int x1, int x2, int line, int val){
    for(int i = x1 ; i < x2 ; i++){
        data[i][line] = val ;
    }
}
void PGM :: drawcross(int x , int y , int val){
    data[x+1][y] = val;
    data[x][y+1] = val;
    data[x-1][y] = val;
    data[x][y-1] = val;
    data[x][y] = val;

}
int PGM :: getW(){
    return width;
}
int PGM :: getH(){
    return height;
}
void PGM :: drawISEN(){
    drawrect(1,1/4,getH()-1,getW()/4,200);
}
void PGM::readFile(char* filename) {
    std::ifstream myfile;
    std::string line;
    std::stringstream s;
    myfile.open(filename);
    if (myfile.is_open()){
        getline(myfile,line);
        s << myfile.rdbuf();
        s >> width >> height;
        s >> maxvalue;
        initImage();
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(data[i][j] != '\n') {
                    s >> data[i][j];
                }
            }
        }

    }
    myfile.close();
}
int PGM :: nbm = 0;
void PGM ::  thresholding(int th, char* filename){
    this->readFile(filename);
    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
            if(data[i][j] >= th){
                data[i][j] = 240;
            }
            else{
                data[i][j] = 0;
            }
        }
    }
}
void PGM:: orderTab(int size,int* tab){
    int j;
    int tmp;
    for(int i=0;i<size;i++){
        j=i;
        while((j > 0) && (tab[j-1] > tab[j])){
            tmp = tab[j-1];
            tab[j-1]=tab[j];
            tab[j]=tmp;
            j--;
        }
    }
}
int PGM:: mediane(int k,int i,int j){
    int c = 0;
    int tab[k*k];

    for(int d = i-(k-1)/2 ; d <= i+(k-1)/2 ; d++){
        for(int e = j-(k-1)/2 ; e <= j+(k-1)/2 ; e++){

            if((d>=0 && d<height) && (e>=0&&e<width)){
                tab[c]=data[d][e];
                c++;
            }
        }
    }
    orderTab(c,tab);
    return tab[(c-1)/2];
}
void PGM ::  filterImage(char* filename, int k){
    this->readFile(filename);

    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){

            this->data[i][j] = this->mediane(k,i,j);

        }
    }
    this->writeFile("image.pgm");
}