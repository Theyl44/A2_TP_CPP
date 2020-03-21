//
// Created by Théo on 1/5/2020.
//

#ifndef TP7_STL_H
#define TP7_STL_H

#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include "Point.h"

template <class T> void printVector(vector <T> tab){
    cout <<"[";
    for(typename vector<T>::iterator it = tab.begin() ; it !=tab.end() ; it++){
        cout <<*it;
        if( it != tab.end()-1){
            cout << ",";
        }
    }
    cout <<"]"<<endl;
}
void PoinTest(){
    Point<float> p(4.3,4.0);
    cout<<"Point(T,T) : " <<&p <<endl;
    cout<<"("<<p.getX()<<","<<p.getY()<<")"<<endl;
    cout<<"~Point() : "<< &p<<endl;
}

void printLetters(){
    vector<char> letters = {'A', 'B', 'C'};
    printVector(letters);
}
void printNumbers(){
    vector<int> numbers = {1,2,3};
    printVector(numbers);
}
void printVectorTests(){
    printNumbers();
    printLetters();
}
bool isNumber(string tab){
    bool verif = true;
    for(char c : tab){
        if(verif){
            verif = isdigit(c);
        }
    }
    return verif;
}

#define boolToString(b) (b ? "true" : "false")

void isNumberTests(){
    cout << boolToString( isNumber("1") )<< endl;
    cout << boolToString( isNumber("42") ) << endl;
    cout << boolToString( isNumber("6PO") ) << endl;
    cout << boolToString( isNumber("R2D2") ) << endl;
}
template <typename T> void keepNumbersOnly(vector<T>& tab){
    for(typename vector<T>::iterator it = tab.begin() ; it != tab.end() ; it++ ){
        if(!isNumber(*it)){
            tab.erase(it);
            it--;
        }
    }
}
void filterVectorTest(){
    vector<string> values = {"Z", "1", "A", "42", "E", "G", "0"};
    keepNumbersOnly(values);
    printVector(values);
}
vector<string> splitString(string s, string c = " "){

    for(auto it = s.begin(); it != s.end() ; it++){
        if(*it == c[0]){
            s.erase(it);
            it--;
        }
    }
    vector<string> result(s.size());
    for(int i=0; i<s.size(); i++){
        result[i] = s[i];
    }
    return result;

}
void splitTests(){

    vector<string> operators = splitString("+ - / =");
    printVector(operators);

    vector<string> numbers = splitString("1,2,3,4,5", ",");
    printVector(numbers);

    vector<string> letters = splitString("A-B-C-D", "-");
    printVector(letters);
}
template <typename T> void printMap(T tab){
    for(auto it : tab){
        cout<<it.first<<"->"<<it.second<<endl;
    }
}
//void printMap(map<string, unsigned short> tab){
//    for(auto it : tab){
//        cout<<it.first<<"->"<<it.second<<endl;
//    }
//}
void printAges(){
    map</*name*/string, /*age*/unsigned short> ages = {
            { "Emma", 30 },
            { "Manon", 19 },
            { "Sacha", 45 }
    };

    printMap(ages);
}
void printRights(){
    map</*userId*/int, /*rights*/int> userRights = {
            { 254756, 666 },
            { 4587, 644 },
            { 58714, 777 }
    };
    printMap(userRights);
}
void printMapTests(){
    printAges();
    cout << "---" << endl;
    printRights();
}
/*
 *
 *
 */
void keepMalesOnly(map<string,bool>& genders){
    for(map<string, bool>::iterator it = genders.begin() ; it!= genders.end() ; it++){
       if(it == genders.begin()){
           it++;
       }
       if(!it->second){
           genders.erase(it);
           it--;
       }
    }
    if(!genders.begin()->second){
        genders.erase(genders.begin());
    }

}
//void keepMalesOnly(map<string,bool>& tab) {
//    for(map<string,bool>::iterator it = tab.begin() ; it != tab.end() ; it++){
//        if(it == tab.begin()){
//            it++;
//        }
//        if(!it->second){
//            tab.erase(it);
//            it--;
//        }
//    }
//    if(!tab.begin()->second) {
//        tab.erase(tab.begin());
//    }
//}
void filterMapTest(){
    map</*name*/string, /*male*/bool> genders = {
            { "Emma", false } ,
            { "Manon", false } ,
            { "Sacha", true } ,
            { "Ambre", false } ,
            { "Gabin", true } ,
            { "Paul", true }
    };
    keepMalesOnly(genders);
    printMap(genders);
}
void splitOnGender(map<string,bool> genders, vector <string>& males, vector<string>& females){
    for(map<string,bool>::iterator it = genders.begin() ; it != genders.end() ; it++){
        if(it->second){
          males.push_back(it->first);
        } else{
            females.push_back(it->first);
        }
    }
}
void splitMapTest(){
    map</*name*/string, /*male*/bool> genders = {
            { "Emma", false } ,
            { "Manon", false } ,
            { "Sacha", true } ,
            { "Ambre", false } ,
            { "Gabin", true } ,
            { "Paul", true }
    };
    vector<string> males;
    vector<string> females;
    splitOnGender(genders, males, females);
    printMap(genders);
    cout << "---" << endl;
    printVector(males);
    printVector(females);
}
map<string,float> computeStatistics(vector<int> values){

    float avg = values[0];
    int max= values[0];
    int min = values[0];
    for(vector<int>::iterator it = values.begin()+1 ; it !=values.end() ; it ++){
        if(*it >= max){
            max  = *it ;
        }
        if(*it <= min){
            min = *it;
        }
        avg = avg + *it;
    }
    avg = avg / values.size();
    map</*name*/string, /*male*/float> result = {
            {"avg",  avg},
            {"max", max},
            {"min", min},
    };
    return result;
}
void statsTest(){
    vector<int> values = {1, 42, -3, 6, 12, 404};
    map<string, float> statistics = computeStatistics(values);
    printMap(statistics);
}

map<string, float> computeStatistics(const vector<int>& values){
    return {
            { "min" , *min_element(values.begin(), values.end()) },
            { "max" , *max_element(values.begin(), values.end()) },
            { "average" , (accumulate(values.begin(),values.end(),0)/values.size()) }
    };
}
#endif //TP7_STL_H
