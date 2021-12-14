//Samochody Dostawczee
//Mateusz Wasilewski
#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int N, wynik, a, x, t;
unordered_map <int,pair<int,int> > mapa;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i^N; ++i){
        cin >> a >> x >> t;
        auto poz = mapa.insert({x-t,{0,0}}).ff;
        if(a == 1) poz->ss.ff++;
        else poz->ss.ss++;
    }
    for(auto poz = mapa.begin(); poz != mapa.end(); ++poz){
        wynik += min(poz->ss.ff,poz->ss.ss);
    }
    cout << wynik << "\n";
    return 0;
}
/*
4
1 5 2
2 3 0
2 3 6
1 7 4
*/