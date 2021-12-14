#include <bits/stdc++.h>

using namespace std;

int N, t, c;
//unordered_map <pair<pair<int,int>,int>,int> mapa;
map <pair<pair<int,int>,int>,int> mapa;

int odp(int x, int y, int k){
    auto poz = mapa.find({{x,y},k});
    if(poz != mapa.end()){
        return poz->second;
    }
    int wynik=0;
    if(x>1) wynik = max(wynik, odp(x-1,y,k-1));
    if(y>1) wynik = max(wynik, odp(x,y-1,k-1));
    if(x<N) wynik = max(wynik, odp(x+1,y,k-1));
    if(y<N) wynik = max(wynik, odp(x,y+1,k-1));
    mapa.insert({{{x,y},k},wynik});
    return wynik;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i=1; i<=N; ++i){
        for(int z=1; z<=N; ++z){
            cin >> c;
            mapa.insert({{{i,z},0},c});
        }
    }
    cin >> t;
    int x, y, k;
    for(int i=0; i<t; ++i){
        cin >> x >> y >> k;
        cout << odp(x,y,k) << "\n";
    }
    return 0;
}
/*
5
9 2 3 4 6
9 9 3 2 1
1 1 2 5 4
1 3 2 2 4
2 2 1 3 2
4
3 4 5
1 2 4
5 5 1
5 4 3

*/