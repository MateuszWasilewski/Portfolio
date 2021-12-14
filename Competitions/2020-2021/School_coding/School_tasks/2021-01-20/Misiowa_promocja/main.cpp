#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
int N, M, a, b, c;
vector <pair<int,int> > v[500001];
vector <int> wyn (500001,-1);

void dfs(int x = 1, int wn = 0){
    wyn[x] = wn;
    for(auto e:v[x]){
        if(wyn[e.ff] == -1) dfs(e.ff, wn^e.ss);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<N; ++i){
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dfs();

    for(int i=0; i<M; ++i){
        cin >> a >> b;
        cout << (wyn[a]^wyn[b]) << "\n";
    }
    return 0;
}
/*
8 4
2 1 3
3 2 17
4 2 13
5 1 6
6 2 9
7 2 2
8 5 10
4 7
5 3
5 1
4 1

*/