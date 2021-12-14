#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,a,b,c=1;
vector <int> v[1000001];
vector <int> odp (1,0);
map <int,int> mapa;

int add(int x){
    auto poz = mapa.insert({x,c});
    if(poz.ss){
        odp.push_back(x);
        c++;
    }
    return poz.ff->ss;
}
void dfs(int x, int y){
    cout<<odp[x]<<" ";
    for(auto e:v[x]){
        if(e != y){
            dfs(e, x);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    add(1);
    cin>>N;
    for(int i=0; i^N; ++i){
        cin>>a>>b;
        a = add(a);
        b = add(b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0);
    cout<<"\n";
    return 0;
}

/*
3
1 2
2 3
3 4

4
4 3
5 2
3 2
4 1

*/