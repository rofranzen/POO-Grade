#include <iostream>
#include <math.h>

class Vetor
{
    int _x;
    int _y;

public:
    Vetor(int x=0, int y=0){
        _x = x;
        _y = y;
    };
    friend Vetor operator+(const Vetor& a, const Vetor& b){
        return Vetor(a._x + b._x, a._y + b._y);
    };
    friend Vetor operator-(const Vetor& a, const Vetor& b){
        return Vetor(a._x - b._x, a._y - b._y);
    };
    friend int operator*(const Vetor& a, const Vetor& b){
        return (a._x * b._x + a._y * b._y);
    };
    friend int operator^(const Vetor& a, const Vetor& b){
        return ( a._x * b._y - a._y * b._x);
    };
    double abs(){
        return sqrt(_x*_x + _y*_y);
    };

    friend double operator<(const Vetor& a, const Vetor& b){
        Vetor c = a;
        Vetor d = b;
        return acos((a*b)/(c.abs()* d.abs()))*180/3.1415;
    };

    friend std::ostream& operator<<(std::ostream &out, const Vetor &a){
        out << "(" << a._x << "," << a._y << ")";
        return out;
    };

};
