#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N;
int tab[1001][1001];
pair<int,int> odp;
pair<pair<int,int>,pair<bool,bool>> rep[1001][1001];
queue <pair<pair<int,int>,pair<int,int> > > pol;
void func(int i, int z, int ii, int zz){
    if(tab[i][z] < tab[ii][zz]) rep[i][z].ss.ff = 0;
    if(tab[i][z] > tab[ii][zz]) rep[i][z].ss.ss = 0;
    if(tab[i][z] == tab[ii][zz]) pol.push({{i,z},{ii,zz}});
    return;
}

pair<int,int> Find(int i, int z){
    if(rep[i][z].ff != make_pair(i,z)){
        rep[i][z].ff = Find(rep[i][z].ff.ff,rep[i][z].ff.ss);
        rep[rep[i][z].ff.ff][rep[i][z].ff.ss].ss.ff &= rep[i][z].ss.ff;
        rep[rep[i][z].ff.ff][rep[i][z].ff.ss].ss.ss &= rep[i][z].ss.ss;
    }
    return rep[i][z].ff;
}
void Union(int i, int z, int ii, int zz){
    pair<int,int> pa = Find(i,z);
    rep[pa.ff][pa.ss].ff = Find(ii,zz);
    Find(i,z);
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; ++i){
        for(int z=1; z<=N; ++z){
            cin >> tab[i][z];
            rep[i][z].ff = {i,z};
            rep[i][z].ss = {1,1};
        }
    }
    for(int i=1; i<=N; ++i){
        for(int z=1; z<=N; ++z){
            if(i>1){
                if(z>1) func(i,z,i-1,z-1);
                if(z<N) func(i,z,i-1,z+1);
                func(i,z,i-1,z);
            }
            if(i<N){
                if(z>1) func(i,z,i+1,z-1);
                if(z<N) func(i,z,i+1,z+1);
                func(i,z,i+1,z);
            }
            if(z>1) func(i,z,i,z-1);
            if(z<N) func(i,z,i,z+1);
        }
    }
    while(!pol.empty()){
        auto now = pol.front();
        Union(now.ff.ff,now.ff.ss,now.ss.ff,now.ss.ss);
        pol.pop();
    }
    for(int i=1; i<=N; ++i){
        for(int z=1; z<=N; ++z){
            if(make_pair(i,z) == Find(i,z)){
                if(rep[i][z].ss.ff) odp.ff++;
                if(rep[i][z].ss.ss) odp.ss++;
            }
        }
    }
    cout << odp.ff << " " << odp.ss << "\n";
    return 0;
}
/*
5
8 8 8 7 7
7 7 8 8 7
7 7 7 7 7
7 8 8 7 8
7 8 8 8 8

5
5 7 8 3 1
5 5 7 6 6
6 6 6 2 8
5 7 2 5 8
7 1 0 1 7
*/