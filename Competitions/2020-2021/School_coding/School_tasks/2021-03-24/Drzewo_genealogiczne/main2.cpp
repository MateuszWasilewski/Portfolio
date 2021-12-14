#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N, a;
int wynik;
map <int,int> mapa;

int main(){
    ios_base::sync_with_stdio((0));
    cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> a;
        auto poz = mapa.insert({a, 0}).ff;
        if(poz != mapa.begin()){
            auto poz1 = poz;
            poz1--;
            poz->ss = max(poz->ss, poz1->ss+1);
        }
        auto poz1 = poz;
        poz1++;
        if(poz1 != mapa.end()){
            poz->ss = max(poz->ss, poz1->ss+1);
        }
        wynik = max(wynik, poz->ss);
    }
    cout << wynik << "\n";
    return 0;
}