//Wycieczka Gorska
//Mateusz Wasilewski
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
using namespace std;

int N,M,k;
ll a,b,wynik;
pair <ll,ll> ans = {LLONG_MAX,0};
pair<int,pair<int,int> > kol;

string line[2001];
ll cost[2001][2001];
//bitset <2001> bt[2001];
priority_queue <pair<int,pair<int,int> > >q;

void add(int c, int x, int y){
    if(c < cost[x][y] && line[x][y]=='.'){
        cost[x][y] = c;
        q.push({-c,{x,y}});
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> k;
    for(int i=0; i^N; ++i){
        cin >> line[i];
        for(int z=0; z^M; ++z){
            cost[i][z] = LLONG_MAX;
        }
    }
    cost[0][0] = 0;
    q.push({0,{0,0}});
    //bt[0][0] = 1;
    while(!q.empty()){
        kol = q.top();
        q.pop();
        //bt[kol.ss.ff][kol.ss.ss] = 0;
        if(kol.ss.ff > 0) add(-kol.ff+1, kol.ss.ff-1, kol.ss.ss);
        if(kol.ss.ss > 0) add(-kol.ff+1, kol.ss.ff, kol.ss.ss-1);
        if(kol.ss.ff < N-1) add(-kol.ff, kol.ss.ff+1, kol.ss.ss);
        if(kol.ss.ss < M-1) add(-kol.ff, kol.ss.ff, kol.ss.ss+1);
    }

    for(int i=0; i^k; ++i){
        cin >> a >> b;
        wynik = a*(N+M-2) + (a+b)*cost[N-1][M-1];
        if(wynik<ans.ff) ans = {wynik,0};
        if(wynik == ans.ff) ans.ss++;
    }

    cout << ans.ff << " " << ans.ss << "\n";
    return 0;
}

/*
5 7 1
......X
X.X..X.
..X.X.X
.X.X...
.....X.
2 1

2 5 4
.X...
...X.
2 1
2 2
1 7
2 1
*/