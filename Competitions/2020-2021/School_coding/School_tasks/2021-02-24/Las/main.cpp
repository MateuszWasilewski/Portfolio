#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

const int sz = 1010;
pair<int,int> rep[sz][sz];
int suma[sz][sz];
int N,d,maxi,a,wynik;
priority_queue <pair<int,pair<int,int> > , vector <pair<int,pair<int,int> > >, greater <pair<int,pair<int,int> > > > q;

pair<int,int> Find(int x, int y){
    if(rep[x][y] != make_pair(x,y)){
        rep[x][y] = Find(rep[x][y].ff, rep[x][y].ss);
        suma[rep[x][y].ff][rep[x][y].ss] += suma[x][y];
        suma[x][y] = 0;
    }
    maxi = max(maxi, suma[rep[x][y].ff][rep[x][y].ss]);
    return rep[x][y];
}

void Union (int x, int y, int x2, int y2){
    pair<int,int> b = Find(x,y);
    pair<int,int> a = Find(x2,y2);

    rep[b.ff][b.ss] = a;
    return;
}

void Pair(int x,int y, int x2, int y2){
    if(rep[x2][y2] != make_pair(0,0)){
        Union(x,y,x2,y2);
    }
    Find(x,y);
    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> d;
    for(int i=1; i<=N; ++i){
        for(int z=1 ; z<=N; ++z){
            cin >> a;
            q.push({a,{i,z}});
        }
    }

    while(maxi < d){
        auto e = q.top();
        q.pop();
        wynik = e.ff;
        suma[e.ss.ff][e.ss.ss]++;
        rep[e.ss.ff][e.ss.ss] = {e.ss.ff,e.ss.ss};

        Pair(e.ss.ff,e.ss.ss,e.ss.ff-1,e.ss.ss);
        Pair(e.ss.ff,e.ss.ss,e.ss.ff,e.ss.ss-1);
        Pair(e.ss.ff,e.ss.ss,e.ss.ff+1,e.ss.ss);
        Pair(e.ss.ff,e.ss.ss,e.ss.ff,e.ss.ss+1);
    }
    cout << wynik << "\n";
    return 0;
}

/*
5 6
3 4 1 2 4
3 1 2 4 6
6 9 1 1 7
1 7 9 4 3
1 1 1 1 6

*/