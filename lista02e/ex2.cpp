#include <iostream>
#include <math.h>


class Trio {
public:
    int a;
    int b;
    int c;

    Trio(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}
};

class Polinomio2
{
    int _a;
    int _b;
    int _c;


public:
    Polinomio2(int a =0, int b =0, int c=0){
        if (a == 0){
            _a = 1;
            _b = 0;
            _c = 0;
        }
        _a = a;
        _b = b;
        _c = c;
        //std::cout << "criado";

    };
    double *raizes(){
        //int qtd;
        double t1,t2, *p = new double[3]();

        double t = _b*_b - 4*_a*_c;
        if (t<0){
            //qtd = 0;
            //std::cout << "chegou no menor que 0";
            p[0] = 0;;
            return p;
        };

        t = sqrt(t);

        t1 = t - _b;
        t2 = -t - _b;
        if(t1 == t2){
            //qtd = 1;
            t1 = t1/(2*_a);
            //std::cout << "chegou no 0";
            p[0] = 1;
            p[1] = t1;
            return p;
        };
        t1 = t1/(2*_a);
        t2 = t2/(2*_a);

        p[0] = 2;
        p[1] = t2;
        p[2] = t1;
        return p;
    };

    double operator()(double x){
        return (_a * x*x + _b * x + _c);
    };

    friend Trio coeficientes(const Polinomio2& p);

};

    Trio coeficientes(const Polinomio2& p) {
        Trio a = Trio(p._a, p._b, p._c);
        return a;
    }

