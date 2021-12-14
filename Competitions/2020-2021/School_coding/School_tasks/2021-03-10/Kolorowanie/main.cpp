#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
using namespace std;

const int half = 200;
int N,a;
ll licz=1;
map <int,int> mapa;
vector <int> v[half*2];
bitset <half*2> used;

void dfs(int x){
    used[x] = 1;
    for(auto e:v[x]){
        if(!used[e]) dfs(e);
    }
    return;
}

int main(){
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> a;
        auto poz = mapa.find(a);
        if(poz != mapa.end()){
            v[poz->ss].push_back(i);
            v[i].push_back(poz->ss);
        }
        else mapa[a] = i;

        v[i+half].push_back(i);
        v[i].push_back(i+half);
    }
    for(int i=0; i<N; ++i){
        cin >> a;

        auto poz = mapa.find(a);
        if(poz != mapa.end()){
            v[poz->ss].push_back(i+half);
            v[i+half].push_back(poz->ss);
        }
        else mapa[a] = i+half;
    }
    for(int i=0; i<N; ++i){
        if(!used[i]){
            licz *= 2;
            dfs(i);
        }
    }
    cout << licz << "\n";
    return 0;
}
/*
5
1 5 3 1 5
4 2 2 4 3

*/