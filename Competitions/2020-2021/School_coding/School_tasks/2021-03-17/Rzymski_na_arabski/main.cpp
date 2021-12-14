#include <bits/stdc++.h>

using namespace std;

map <char,int> mapa;

int maxi = 0,a;
int wynik = 0;
string word;
int main(){
    mapa['I'] = 1;
    mapa['V'] = 5;
    mapa['X'] = 10;
    mapa['L'] = 50;
    mapa['C'] = 100;
    mapa['D'] = 500;
    mapa['M'] = 1000;
    cin >> word;
    for(int i = word.size()-1; i>=0; --i){
        a = mapa[word[i]];
        if(a < maxi) wynik -= a;
        else wynik += a;
        maxi = max(maxi,a);
    }
    cout << wynik << "\n";
}