#include <iostream>

class Fracao
{
  BigInt _numerador;
  BigInt _denominador;

public:
    Fracao(BigInt numerador = 0, BigInt denominador = 1): _numerador(0), _denominador(1){
        _numerador = numerador;
        _denominador = denominador;
    };
    friend Fracao operator/(const Fracao& a, const Fracao& b){
        BigInt den = a._denominador * b._numerador;
        BigInt num = b._denominador * a._numerador;


        Fracao f(num, den);
        return f;
    };
    friend Fracao operator*(const Fracao& a, const Fracao& b){
        BigInt den = a._denominador * b._denominador;
        BigInt num = b._numerador * a._numerador;


        Fracao f(num, den);
        return f;
    };
    friend Fracao operator+(const Fracao& a, const Fracao& b){
        BigInt num = b._numerador * a._denominador + a._numerador * b._denominador;
        BigInt den = a._denominador * b._denominador;

        Fracao f(num, den);
        return f;
    };
    friend Fracao operator-(const Fracao& a, const Fracao& b){
        BigInt num = -b._numerador * a._denominador + a._numerador * b._denominador;
        BigInt den = a._denominador * b._denominador;

        Fracao f(num, den);
        return f;
    };


    friend std::ostream& operator<<(std::ostream &out, const Fracao &a){
        out << a._numerador << "/" << a._denominador;
        return out;
    };
};
