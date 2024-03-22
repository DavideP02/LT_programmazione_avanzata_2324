// Lezione 2

#include <iostream>
#include <math.h>

using namespace std;

// GCD esterno

int gcd(int a, int b) 
{ 
    // Find Minimum of a and b 
    int result = min(a, b); 
    while (result > 0) { 
        if (a % result == 0 && b % result == 0) { 
            break; 
        } 
        result--; 
    } 
  
    // Return gcd of a and b 
    return result; 
} 

/*
    # Classe

    Si tratta di una astrazione di tipo logico. Finché non creiamo gli oggetti che la compongono è come se non esistesse. 

    È composta da oggetti, che hanno la stessa rappresentazione in memoria e supportano le stesse operazioni. 

    La classe è composta di due parti, una **privata** e una **pubblica**.
    Questo prende il nome di **PRINCIPIO DI INCAPSULAMENTO**

    class rat {
        private: 
            ...
        public: 
            ...
    };
*/

class rat {
    private: 
        int num;
        int den; // den > 0

    public: 
        rat(int, int = 1); // dichiarazione del costrutture, che poi va definito
        int get_num() const { return num; } // **metodo** pubblico
        int get_den() const { return den; } // **metodo** pubblico
        /*
            Osservo che inserisco "const" per fare sapere al compilatore che questi metodi **non** modificano gli oggetti: in questo modo mi proteggo. 
        */
       rat add(const rat&) const; // dichiarazione di un metodo pubblico
       rat neg() const;
       rat sub(const rat&) const;
       rat mul(const rat&) const;
       rat recip() const;
       rat div(const rat&) const;
       void print() const;
       rat reduce() const;
       rat pow_nn(int) const;
       rat pow(int) const;
};

rat::rat(int a, int b) { // definizione del costruttore 
/*
    Il rat:: richiama la classe rat. Questo è un operatore di risoluzione di ambito
*/
    if (b > 0) {
        num = a; 
        den = b;
    } else if (b < 0) {
        num = -a; 
        den = -b;
    } else throw domain_error("division by zero");
}
rat rat::add(const rat& b) const { // definizione del metodo add
    return rat(num * b.den + b.num * den, den *b.den);
}
rat rat::neg() const {
    return rat(-num, den);
}
rat rat::sub(const rat& b) const {
    return add(b.neg());
}
rat rat::mul(const rat& b) const {
    return rat(num * b.num, den * b.den);
}
rat rat::recip() const {
    return rat(den, num);
}
rat rat::div(const rat& b) const {
    return mul(b.recip());
}
void rat::print() const {
    if (den == 1) {
        cout << num << endl;
    } else {
        cout << num << "/" << den << endl;
    }
}
rat rat::reduce() const {
    int d = gcd(num, den); //TODO da sistemare
    // int d = 1;
    int nnum = num / d; 
    int nden = den / d;
    return rat(nnum, nden);
}
rat rat::pow_nn(int n) const {
    if (n == 0) {
        return rat(1); 
    } else if (n > 0) {
        int nnum = (int) ::pow((double) num, (double) n);
        int nden = (int) ::pow((double) den, (double) n); 
        return rat(nnum, nden);
    } else throw domain_error("division by zero");
}
rat rat::pow(int n) const {
    if (n >= 0) {
        return pow_nn(n);
    } else if (n < 0) {
        return recip().pow_nn(-n);
    }
}

int main() {
    rat r = rat(2,4);
    r.reduce().print();
}