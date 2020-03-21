
#ifndef TP7_POINT_H
#define TP7_POINT_H
template<typename T> class Point{
private :
    T x; T y;
public:


    Point(T x, T y);
    ~Point();


    T getX() const;

    T getY() const;

    void setX(T x);

    void setY(T y);

};

template<typename T> Point<T> ::Point(T x, T y) {
  this->x = x;
  this->y = y;
}
template <typename T> Point<T> :: ~Point(){

}

template<typename T>
void Point<T>::setX(T x) {
    Point::x = x;
}

template<typename T>
void Point<T>::setY(T y) {
    Point::y = y;
}

template<typename T>
T Point<T>::getX() const {
    return x;
}

template<typename T>
T Point<T>::getY() const {
    return y;
}

#endif //TP7_POINT_H
