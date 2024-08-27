// ESERCIZIO 3

// #include <iostream>
// #include <math.h>
// #include <stdexcept>

// using namespace std;

// class giacca {
//     private:
//         int taglia; // 30 <= taglia <= 60
//         int cerniera; // percentuale (tra 0 e 100)
//     public:
//         giacca(int, int = 100);
//         void open() {cerniera = 0;};
//         void close() {cerniera = 100;};
//         void open_of(int);
//         void close_of(int);
//         int get_cerniera() {return cerniera;};
// };

// giacca::giacca(int a, int b) {
//     if (30 <= a && a <= 60) {
//         taglia = a;
//     } else throw domain_error("La taglia deve essere compresa tra 30 e 60");
//     if (0 <= b && b <= 100) {
//         cerniera = b;
//     } else throw domain_error("La percentuale di apertura della cerniera deve essere in percentuale");
// }

// void giacca::open_of(int a) {
//     if (a > cerniera) {
//         cerniera = 0;
//     } else if (a > 0) {
//         cerniera = cerniera - a;
//     } else throw domain_error("Inserire un nunmero positivo");
// }

// void giacca::close_of(int a) {
//     if (a < 0) {
//         throw domain_error("Inserire un nunmero positivo");
//     }
//     if (a + cerniera > 100) {
//         cerniera = 100;
//     } else {
//         cerniera = cerniera + a;
//     }
// }

// int main() {
//     giacca a(31,12);
//     a.open();
//     int x = a.get_cerniera();
//     cout << x << endl;
//     a.close_of(-150); 
//     cout << a.get_cerniera();
// }

// ESERCIZIO 4

// #include <iostream>
// #include <stdexcept>

// using namespace std;

// class treno {
//     private:
//         int vagoni;
//         int cap_vagone;
//         int passeggeri;
//     public:
//         treno(int, int, int = 0);
//         void sali_scendi(int);
//         int get_passeggeri() {return passeggeri;};
//         double get_mean_passeggeri() {return passeggeri/vagoni;};
// };

// treno::treno(int a, int b, int c) {
//     if (a > 0) {
//         vagoni = a;
//     } else throw domain_error("Inserire numeri positivi;");
//     if (b > 0) {
//         cap_vagone = b;
//     } else throw domain_error("Inserire numeri positivi;");
//     if (c >= 0) {
//         passeggeri = c;
//     } else throw domain_error("Inserire numeri positivi;");
// }

// void treno::sali_scendi(int a) {
//     if (a + passeggeri < cap_vagone * vagoni) {
//         if (a + passeggeri < 0) {
//             passeggeri = 0;
//         } else {passeggeri = a + passeggeri;};
//     } else throw throw domain_error("Capacità massima raggiunta");
// }

// int main() {
//     treno trenino_thomas(3,150);
//     cout << trenino_thomas.get_mean_passeggeri() << endl;
//     cout << trenino_thomas.get_passeggeri() << endl;
//     trenino_thomas.sali_scendi(-150);
//     cout << trenino_thomas.get_mean_passeggeri() << endl;
//     cout << trenino_thomas.get_passeggeri() << endl;
//     trenino_thomas.sali_scendi(300);
//     cout << trenino_thomas.get_mean_passeggeri() << endl;
//     cout << trenino_thomas.get_passeggeri() << endl;
//     trenino_thomas.sali_scendi(500);
//     cout << trenino_thomas.get_mean_passeggeri() << endl;
//     cout << trenino_thomas.get_passeggeri() << endl;
// }

// ESERCIZIO 6

#include <iostream>
#include <stdexcept>

using namespace std;

class dispenser {
    private:
        int capienza;
        int quant = 0;
        int erogato;
    public:
        dispenser(int = 500, int = 10);
        void eroga();
        void ricarica(int);
        int get_quant() {return quant;};
};

dispenser::dispenser(int a, int b) {
    if (a > 0) {
        capienza = a;
    } else throw domain_error("La capienza deve essere positiva");
    if (b > 0 && b < a) {
        erogato = b;
    } else throw domain_error("Fuori dal domain range");
}
void dispenser::eroga() {
    if (erogato > quant) {
        quant = 0;
    } else {
        quant -= erogato;
    }
}
void dispenser::ricarica(int a) {
    if (a > 0 && a <= capienza - quant) {
        quant += a;
    } else throw domain_error("Domain Range");
}

int main() {
    dispenser standard;
    cout << standard.get_quant() << endl;
    standard.ricarica(500);
    cout << standard.get_quant() << endl;
    standard.eroga();
    standard.eroga();
    standard.eroga();
    standard.eroga();
    standard.eroga();
    standard.eroga();
    cout << standard.get_quant() << endl;
}