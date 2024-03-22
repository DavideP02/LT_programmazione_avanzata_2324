// Lezione 3

#include <iostream>
#include <math.h>

using namespace std;

class complex {
    private: 
        double real;
        double im;

    public:
        complex(double =0, double = 0);
        double getreal();
        double getim();
        complex add(complex);
        complex sub(complex);
        complex neg();
        complex mul(complex);
        complex reciproco();
        double modulo();
        complex div(complex);
        complex coniugato();
        void print();
};
complex::complex(double a, double b) {
    real = a;
    im = b;
}
double complex::getreal() {
    return real;
}
double complex::getim() {
    return im;
}
complex complex::add(complex a) {
    return complex(real + a.real, im + a.im);
}
complex complex::sub(complex a) {
    return complex(real - a.real, im - a.im);
}
complex complex::neg() {
    return complex(-real, -im);
}
complex complex::mul(complex a) {
    return complex(real * a.real - im * a.im, real * a.im + im * a.real);
}
complex complex::div(complex a) {
    return mul(a.reciproco());
}
complex complex::reciproco() {
    if (real == 0 && im == 0) {
        throw domain_error("division by zero");
    } else {
        double m = 1/(modulo() * modulo());
        return complex(m * real, - m * im);
    } 
}
double complex::modulo() {
    return sqrt(real*real + im*im);
}
complex complex::coniugato() {
    return complex(real, -im);
}
void complex::print() {
    if (im > 0) {
        cout << real << " +" << im << "i" << endl;
    } else if (im == 0) {
        cout << real << endl;
    } else {
        cout << real << " " << im << "i" << endl;
    }
}

complex operator+(complex a, complex b) {
    return a.add(b);
}
complex operator-(complex a, complex b) {
    return a.sub(b);
}
complex operator*(complex a, complex b) {
    return a.mul(b);
}
complex operator/(complex a, complex b) {
    return a.div(b);
}
std::ostream& operator<<(std::ostream& os, complex a) {
    if (a.getim() > 0) {
        os << a.getreal() << " +" << a.getim() << "i" << endl;
    } else if (a.getim() == 0) {
        os << a.getreal() << endl;
    } else {
        os << a.getreal() << " " << a.getim() << "i" << endl;
    }
    return os;
}

int main() {
    complex a(1,2);
    complex b(1,-2);
    complex r = a+b;
    a.add(b).print();
    cout << a+b;
}