#include <iostream>

using namespace std;

class C {
private:
    double _real;
    double _imag;

public:

    C(double _real = 0.0, double _imag = 0.0) : _real(_real), _imag(_imag) {
    }

    virtual void print(ostream& os) const {
        if (_imag != 0)
            os << _real << " + " << _imag << "i";
        else
            os << _real;
    }
    double getReal() const {
        return _real;
    }
    double getImag() const {
        return _imag;
    }
};

class R : public C {

public:
    R(double _real = 0.0) : C(_real, 0.0) {
    }

    void print(ostream& os) const override {
        os << getReal();
    }
};

class Q : public R {

private:

    double _numerador;
    double _denominador;
public:

    Q(double _numerador = 0, double _denominador = 1) : _numerador(_numerador), _denominador(_denominador), R(_numerador / _denominador) {
    }

    double getNumerador() const {
        return _numerador;
    }
    double getDenominador() const {
        return _denominador;
    }

    void print(ostream& os) const override {
        os << _numerador << "/" << _denominador;
    }
};

class Z : public Q {
public:
    Z(double _valor = 0) : Q(_valor, 1) {
    }

    void print(ostream& os) const override {
        double number = getNumerador();
        if (number > 0) {
            os << "+" << number;
        } else {
            os << number;
        }
    }
};

class N : public Z {
public:
    N(double _valor = 0) : Z(_valor) {
    }

    void print(ostream& os) const override {
        os << getNumerador();
    }
};

ostream& operator<<(ostream& os, const C& c) {
    c.print(os);
    return os;
}

ostream& operator<<(ostream& os, const R& r) {
    r.print(os);
    return os;
}

ostream& operator<<(ostream& os, const Q& q) {
    q.print(os);
    return os;
}

ostream& operator<<(ostream& os, const Z& z) {
    z.print(os);
    return os;
}

ostream& operator<<(ostream& os, const N& n) {
    n.print(os);
    return os;
}
