// Lezione 8

// Dispense su vettori e liste

#include <iostream>
#include <list>
#include <math.h>

using namespace std;

class Set {
    private:
        list<int> data;
    public:
        int size() const { return data.size(); }
        bool contains(int) const;
        void insert(int);
        void remove(int);
        friend ostream& operator<<(ostream&, const Set&);
        bool empty() const;
        vector<int> elements() const;
        int minimum() const;
        int maximum() const;
        Set _union(const Set) const;
        Set intersection(const Set) const;
        Set difference(const Set) const;
        bool overlap(const Set) const;
};
int Set::minimum() const {
    list<int>::const_iterator it = data.cbegin();
    return *it;
}
int Set::maximum() const {
    list<int>::const_iterator it = data.cend();
    it--;
    return *it;
}
vector<int> Set::elements() const {
    vector<int> v(size()); 
    list<int>::const_iterator it = data.cbegin();
    int i = 0;
    while (it != data.cend()) {
        v[i] = *it;
        it++;
        i++;
    }
    return v;
}
bool Set::empty() const {
    list<int>::const_iterator inizio = data.cbegin();
    // inizio++; // cend()++ è uguale a cend()
    list<int>::const_iterator fine = data.cend();
    if (inizio == fine) return true;
    return false;
}
bool Set::contains(int x) const {
    list<int>::const_iterator it = data.cbegin();
    while (it != data.cend() && *it < x) it++;
    return it != data.cend() && *it == x;
}
void Set::remove(int x) {
    list<int>::iterator it = data.begin();
    while (it != data.end() && *it < x) it++;
    if (it != data.end() && *it == x) data.erase(it);
}
void Set::insert(int x) {
    list<int>::iterator it = data.begin();
    while (it != data.end() && *it < x) it++;
    if (it == data.end() || *it != x) data.insert(it, x);
}
ostream& operator<<(ostream& os, const Set& s) {
    cout << "{";
    list<int>::const_iterator it = s.data.cbegin();
    while (it != s.data.cend()) {
        cout<< *it;
        it++;
        if (it != s.data.cend()) cout<< ", ";
    }
    cout << "}";
    return os;
}
Set Set::_union(const Set a) const {
    Set prova;

    list<int>::const_iterator it = data.cbegin();
    while (it != data.cend()) {
        prova.insert(*it);
        it++;
    }

    list<int>::const_iterator iit = a.data.cbegin();
    while (iit != a.data.cend()) {
        prova.insert(*iit);
        iit++;
    }
    return prova;
}
Set Set::intersection(const Set a) const {
    Set prova;

    list<int>::const_iterator it = data.cbegin();
    while (it != data.cend()) {
        if (a.contains(*it) && contains(*it)) {
            prova.insert(*it);
        }
        it++;
    }

    return prova;
}
Set Set::difference(const Set a) const {
    Set prova;

    list<int>::const_iterator it = data.cbegin();
    while (it != data.cend()) {
        prova.insert(*it);
        if (a.contains(*it)) {
            prova.remove(*it);
        }
        it++;
    }

    return prova;
}
bool Set::overlap(const Set a) const {
    return !intersection(a).empty();
}

int main() {
    Set ciao;
    Set set2;
    for (int i = 1; i < 15; i++) ciao.insert(i);
    for (int i = 10; i < 20; i++) set2.insert(i);
    // cout << ciao.empty() << endl;;
    // vector<int> v = ciao.elements();
    // cout << "{";
    // for (int i = 0; i < 9; i++) cout << v[i] << " ";
    // cout << "}";
    // cout << ciao.minimum() << endl;
    // cout << ciao.maximum() << endl;
    cout << ciao << endl;
    cout << set2 << endl;
    cout << ciao.difference(set2) << endl;
    cout << set2.difference(ciao) << endl;
    cout << ciao.overlap(set2) << endl;
    cout << set2.overlap(ciao) << endl;
}