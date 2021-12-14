#include <bits/stdc++.h>


using namespace std;

int N,a;
string line;
int tab[150];
int wynik;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> line;

    for(int i=0;i<N; ++i){
        a = line[i];
        tab[a] = 1;
        if(tab[a^32] > 0) wynik++;
    }
    cout << wynik << "\n";
}
/*
6
AnaNas

15
aAaAbaABBabbBbB
*/