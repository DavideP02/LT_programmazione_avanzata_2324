// Lezione 1

#include <math.h>
#include <iostream>

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

// Dalla lezione:

struct rat {
    int num;
    int den;
};

rat rational(int a, int b = 1) {
    if (b > 0) {
        rat r = { a, b };
        return r;
    } else if (b < 0) {
        rat r = { -a, -b };
        return r;
    } else throw domain_error("division by zero");
}
rat rational(double a, int n) {
    int m = pow(10, n);
    return rational((int) (a * m), m);
}
int to_int(const rat& r) {
    return r.num / r.den;
}
double to_double(const rat& r) {
    return (double) r.num / r.den;
}
rat add(const rat& a, const rat& b) {
    return rational(a.num * b.den + b.num * a.den, a.den * b.den);
}
rat neg(const rat& a) {
    return rational(-a.num, a.den);
}
rat operator+(const rat& a, const rat& b) {
    return add(a, b);
}

// ESERCIZIO 2

rat sub(const rat& a, const rat& b) {
    return rational(a.num * b.den - b.num * a.den, a.den * b.den);
}
rat mul(const rat& a, const rat& b) {
    return rational(a.num * b.num, a.den * b.den);
}
rat recip(const rat& a) {
    return rational(a.den, a.num);
}
rat div(const rat& a, const rat& b) {
    return rational(a.num * b.den, a.den * b.num);
}

// ESERCIZIO 3

void print(const rat& a) {
    if (a.den == 1) {
        cout << a.num << endl;
    } else {
        cout << a.num << "/" << a.den << endl;
    }
}

// ESERCIZIO 4

rat reduce(const rat& a) {
    int apos = abs(a.num);
    int d = gcd(apos, a.den);
    int num = a.num / d;
    int den = a.den / d;
    return rational(num, den);
}

// ESERCIZIO 5

rat pow_nn(const rat& a, int n) {
    int num = pow(a.num, n);
    int den = pow(a.den, n);
    return rational(num, den);
}

// ESERCIZIO 6

rat pow(const rat& a, int n) {
    if (n > 0) {
        return pow_nn(a,n);
    } else if (n<0) {
        return recip(pow_nn(a,-n));
    } else {
        return rational(1);
    }
} 

int main () {

    rat r = rational(1,2);
    print(r);
    rat d = pow(r, 3); 
    print(d);
    rat f = rational(3,6);
    print(reduce(f));
    system("pause");
}
