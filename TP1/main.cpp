#include <iostream>

using namespace std;

void exo1();
void exo2();
void max(int n);
void max(int n, int m);
void max(int n, int m, int r);
void exo4(int* a , int* b);
void exo4(int& a , int& b);
int sum(int n);
int sum2(int n, int limite = 1);
void sum3(int n,int& result,int limite = 0);
void sum4(int n, int& result, int limite = 0);
void sum5(int n, int& result,int limite = 0);
int main() {


//    int i = 6;
//    int s = 15;
//    sum5(i,s,42);
//    cout << s << endl;
//    sum5(i, s, 4); // s contient 15
//    cout << s <<endl;
//    int n = sum2(6,4);
//    cout << n;
////    int b = 6;
//    int n = sum(b);
//    cout <<" sum("<<b<<") = "<< n<<endl;

    int a = 0;
    int b = 1;
    cout <<"a = "<<a<<"; b = "<<b<<endl;
    exo4(a,b);
    cout <<"a = "<<a<<"; b = "<<b<<endl;


    return 0;
}
void sum5(int n, int& result,int limite){
    if (limite < n) {
        if (n == limite) {
            result = limite;
        } else {
            result = n + sum2(n - 1, limite);
        }
    }else{
        cout << "error" << endl;
    }
}
void sum4(int n, int& result, int limite) {
    if (limite < n) {
        if (n == limite) {
            result = limite;
        } else {
            result = n + sum2(n - 1, limite);
        }
    }
    else{
        cout<<"error"<<endl;
    }
}
void sum3(int n,int& result,int limite){
    if(n == limite) {
        result = limite;
    }
    else{
        result =  n + sum2(n-1,limite);
    }
}
int sum2(int n, int limite){
    if(n == limite) {
        return limite;
    }
    else{
        return n + sum2(n-1,limite);
    }
}
int sum(int n){
    if(n == 0)
        return 0;
    else{
        return n + sum(n-1);
    }
}
void exo4(int* a , int* b){
    int valtemp = *a;
    *a = *b;
    *b = valtemp;
}
void exo4(int& a , int& b){
    int valtemp = a ;
    a = b;
    b = valtemp;
}
void max(int n){
    cout << n << " est votre val max" << endl;
}
void max(int n, int m){
    if(n > m){
        cout << n << " est votre val max" << endl;
    }
    else{
        cout << m << " est votre val max" << endl;
    }
}
void max(int n, int m, int r){
  if(n > m){
      if(n > r){
          cout << n << " est votre val max" << endl;
      }else{
          cout << r << " est votre val max" << endl;
      }
  }
  else{
      if(m > r){
          cout << m << " est votre val max" << endl;
      }else{
          cout << r << " est votre val max" << endl;
      }
  }
}
void exo2(){
    cout << "------------TAB------------" << endl;
    auto n = 0 ;
    int* tab;
    cout << "combien de case ? " << endl;
    cin >> n;
    if (n > 0){
         tab = new int[n];
        int a = 0;
        int b = n;
        while(b>0){
            cout << "entrez un val :" << endl;
            cin >> tab[a];
            a++;
            b--;
        }
        float moyenne=0;
        for(int i = 0 ; i < n ; i++){
            moyenne = moyenne + (float)tab[i];
        }
        moyenne  = moyenne /n;
        cout << "votre moyenne est : " << moyenne << endl;

        delete[] tab;
    }
}
void exo1(){
    int v1,v2;
    int result;
    bool b1,b2;
    cout << "------------SOMME------------" << endl;
    cout << "val1  =" << endl;
    cin >> v1;
    cout << "val2  =" << endl;
    cin >> v2;
    result = v1 +v2;
    cout <<"\n"<< v1<< " + " << v2 <<" = "<< result << endl;

    cout << "Positif ? ";
    if(result > 0){
        cout << "true" << endl;
        b1 = true;
        b2 = false;
    }
    else{
        cout << "false ou nul"<< endl;
        b1 = false;
        b2 = true;
    }

}