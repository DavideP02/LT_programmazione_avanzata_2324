#include <iostream>  //stampa su terminale
#include <fstream>  //lettura da file
#include <map>  //fasi 1 e 2
#include <cstring> // tolowere
#include <vector>  //fasi 3-5
#include <algorithm>  //fase 4
#include <cctype>  //filtro per i caratteri

#define daaprire "bibbiaa.txt"

using namespace std;


typedef pair<string, int> WordCount;
typedef map<string, int> WordCountMap;
typedef vector<WordCount> WordCountVec;

bool valid(string a) {
    for (int i = 0; i < a.size(); i++) {
        if (!isalpha(a[i])) return false;
    }
    return true;
}

string STRING_lower(string w) {
    string m = w;
    for(int i = 0; i < w.size(); i++) {
        m[i] = (char) tolower(w[i]);
    }
    return m;
}

WordCountMap lower_read_word_map(istream& is) {
    WordCountMap m;
    string w;
    while (is >> w) {
        if (valid(w)) m[STRING_lower(w)]++;
        // if (valid(w)) m[w]++;
    }
    return m;
}

WordCountMap UPPER_read_word_map(istream& is) {
    WordCountMap m;
    string w;
    while (is >> w)
        if (valid(w) && isupper(w[0])) m[w]++;
    return m;
}

bool Compare(WordCount p, WordCount q) {
    return p.second > q.second;
}

WordCountVec sort_word_map(WordCountMap m) {
    WordCountVec v = WordCountVec(m.begin(), m.end());
    sort(v.begin(), v.end(), Compare);
    return v;
}

bool Compare_by_lenght(WordCount p, WordCount q) {
    return p.first.size() > q.first.size();
}

WordCountVec sort_by_lenght_word_map(WordCountMap m) {
    WordCountVec v = WordCountVec(m.begin(), m.end());
    sort(v.begin(), v.end(), Compare_by_lenght);
    return v;
}
int main() {
    cout << "Parole più frequenti:" << endl;
    ifstream f(daaprire);
    WordCountMap m = lower_read_word_map(f);
    WordCountVec v = sort_word_map(m);
    for (int i = 0; i < 10 && i < v.size(); i++) {
        cout << v[i].first << ": " << v[i].second << endl;
    }

    WordCountVec v_by_lenght = sort_by_lenght_word_map(m);
    cout << endl << "La parola più lunga è " << v_by_lenght[0].first << " e compare " << v_by_lenght[0].second << " volte" << endl << endl;

    cout << endl << "Compaiono " << v.size() << " parole diverse" << endl << endl;

    cout << "Parole maiuscole più frequenti:" << endl;
    ifstream F(daaprire);
    WordCountMap M = UPPER_read_word_map(F);
    WordCountVec V = sort_word_map(M);
    for (int j = 0; j < 50 && j < V.size(); j++) {
        cout << V[j].first << ": " << V[j].second << endl;
    }
}