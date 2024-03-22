#include <iostream>
#include <math.h>

using namespace std;

class Primi {
    private:
        int primo;

    public:
        Primi();
        void next();
        bool is_prime();
        void print();
};

Primi::Primi() {
    primo = 2;
}
void Primi::print() {
    cout << primo << endl;
}
bool Primi::is_prime() {
    for (int i = 2; i <= sqrt(primo); i++) {
        if (primo % i == 0) {
            return false;
        }
    }
    return true;
}
void Primi::next() {
    primo++;
    while (!is_prime()) {
        primo++;
    }
}

int main() {
    Primi p;
    for (int i = 1; i < 100; i++) {
        p.print();
        p.next();
    }
}