#include <iostream>
#include <math.h>

using namespace std;

class Vector {
    private:
        vector<int> vettore;

    public:
        Vector(int);
        int size();
        int operator[](int) const;
        int& operator[](int);
        int scalare(Vector&);
        double norma(); 
        Vector per_scalari(int);
        Vector somma(Vector);
        Vector sottrazione(Vector);
        void print();
};
Vector::Vector(int a) {
    if (a < 0) {
        throw domain_error("invalid size");
    }
    vettore.resize(a, 0);
}
int Vector::size() {
    return vettore.size();
}
int Vector::operator[](int i) const {
    return vettore.at(i);   
}
int& Vector::operator[](int i) {
    return vettore.at(i);   
}
int Vector::scalare(Vector& v) {
    if (size() !=  v.size()) {
        throw domain_error("invalid size");
    }
    int risultato = 0;
    for (int i = 0; i < size(); i++) {
        risultato += vettore[i] * v.vettore[i];
    }
    return risultato;
}
double Vector::norma() {
    Vector v = Vector(size());
    for (int i = 0; i < size(); i++) {
        v[i] = vettore[i];
    }
    return (double) sqrt((double) scalare(v));
}
void Vector::print() {
    cout << "(" << vettore[0];
    for (int i = 1; i < size(); i++) {
        cout << "; " << vettore[i];
    }
    cout << ")" << endl;
}
Vector Vector::per_scalari(int a) {
    Vector v = Vector(size());
    for (int i = 0; i < size(); i++) {
        v[i] = vettore[i] * a;
    }
    return v;
}
Vector Vector::somma(Vector a) {
    Vector v = Vector(size());
    for (int i = 0; i < size(); i++) {
        v[i] = vettore[i] + a.vettore[i];
    }
    return v;
}
Vector Vector::sottrazione(Vector a) {
    Vector v = Vector(size());
    for (int i = 0; i < size(); i++) {
        v[i] = vettore[i] - a.vettore[i];
    }
    return v;
}

class Matrix {
    private:
        vector<Vector> matrice;

    public:
        Matrix(int, int);
        int righe();
        int colonne();
        Vector operator[](int) const;
        Vector& operator[](int);
        // int scalare(Vector&);
        void print();
};

Matrix::Matrix(int a, int b) {
    if (a <= 0 || b<= 0) throw domain_error("invalid size");
    matrice.resize(a,0);
    for (int i = 0; i < a; i++) {
        matrice[i] = Vector(b);
    }
}
int Matrix::righe() {
    return matrice.size();
}
int Matrix::colonne() {
    return matrice[0].size();
}
Vector Matrix::operator[](int a) const {
    return matrice[a];
}
Vector& Matrix::operator[](int a) {
    return matrice[a];
}
void Matrix::print() {
    for (int a = 0; a < righe(); a++){
        matrice[a].print();
    }
}
int main() {
    Matrix m(2,3);
    cout << m.righe() << "; " << m.colonne() << endl; 
    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[1][0] = 4;
    m[1][1] = 5;
    m[1][2] = 6;
    m.print();
}