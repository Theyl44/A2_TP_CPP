#include "Point.h"

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();
void test10();
void test11();
void test12();

int main() {

//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test6();
//    test7();
//    test8();
//    test9();
//    test10();
//    test11();
//    test12();

    return 0;
}

void test1(){
    Point p;
    p.afficher();
}
void test2(){
    Point p();//mauvaise appel ??? il croit qu'on appelle une fonction
}
void test3(){
    Point p(1,2);
    p.afficher();
}
void test4(){
    Point p(4);
    p.afficher();
}
void test5(){
    Point* p = new Point;
    p->afficher();
}
void test6(){
    Point* p = new Point();
    p->afficher();
}
void test7(){
    Point* p = new Point(4);
    p->afficher();
}
void test8(){
    Point* p = new Point(1,2);
    p->afficher();
}

void test9(){
    Point p = {1,2};
    p.afficher();
}

void test10(){
    Point p1(1,2);
    Point p2 = p1;
    p1.afficher();
    p2.afficher();
}

void test11(){
    Point p1(1,2);
    Point p2;
    p1 = p2;
    p1.afficher();
    p2.afficher();
}

void test12(){
    Point* p1 = new Point(1,2);
    Point* p2 = p1;
    p1->afficher();
    p2->afficher();
}