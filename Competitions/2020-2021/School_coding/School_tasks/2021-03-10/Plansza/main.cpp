#include <bits/stdc++.h>
#define sz 4000
#define ff first
#define ss second
using namespace std;

bitset <sz> bt[sz];
int tab[sz][sz];
string line;
int N,M,a,b;
int aa,bb;
priority_queue<pair<int,pair<int,int>> , vector <pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>> > > q;

void add(int x, int y, int c){
    if(x <= N && x >= 1 && y <= M && y >= 1){
        if(tab[x][y] > c && bt[x][y]){
            tab[x][y] = c;
            q.push({c,{x,y}});
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    cin >> a >> b >> aa >> bb;
    for(int i=1; i<=N; ++i){
        cin >> line;
        for(int z=1; z<=M; ++z){
            bt[i][z] = (line[z-1] == '.');
            tab[i][z] = INT32_MAX;
        }
    }
    tab[a][b] = 0;
    q.push({0,{a,b}});
    while(!q.empty()){
        auto e = q.top();
        q.pop();
        a = e.ss.ff;
        b = e.ss.ss;
        if(e.ff == tab[e.ss.ff][e.ss.ss]){
            add(a-1,b,e.ff);
            add(a,b-1,e.ff);
            add(a+1,b,e.ff);
            add(a,b+1,e.ff);
            e.ff++;
            add(a-2,b,e.ff);
            add(a,b-2,e.ff);
            add(a+2,b,e.ff);
            add(a,b+2,e.ff);
        }
    }
    if(tab[aa][bb] == INT32_MAX) cout << "-1\n";
    else cout << tab[aa][bb] << "\n";
}
/*
3 4
2 2 2 4
####
#.#.
####

5 11
2 11 4 2
####.#.####
#..#.#.#...
#..#.#.#.##
#..#.#.#..#
####.#.####

2 2
1 1 2 2
.#
#.
*/