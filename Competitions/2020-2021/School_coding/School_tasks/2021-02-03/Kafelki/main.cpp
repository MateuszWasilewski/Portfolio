#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,M;
unordered_map <int,int> mapa;
int tab[1000001];

int NWD(int a, int b){
    int pom;
    while(b!=0){
        pom = b;
        b = a%b;
        a = pom;
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b;
    cin >> N >> M;
    
    for(int i=0; i<N; ++i){
        cin >> a;
        auto poz = mapa.insert({a,1});
        if(!poz.ss) poz.ff->ss++;
    }
    for(int i=1; i<1000001; ++i){
        auto poz = mapa.find(i);
        if(poz != mapa.end()){
            for(int z=i; z<1000001; z+=i){
                tab[z] += poz->ss;
            }
        }
    }

    for(int i=0; i<M; ++i){
        cin >> a >> b;
        cout << tab[NWD(a,b)] << "\n";
    }
    return 0;
}
/*
3 4
3 2 7
3 5
14 7
14 14
18 10

6 4
1 1 2 2 3 3
1 1
2 2
6 12
12 6
*/