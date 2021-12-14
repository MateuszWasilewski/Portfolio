#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

const int size = 100;


//DFS
vector <int> v[size];

void DFS(int x, int y){
    //Do sth

    for(auto e:v[x]){
        if(x !=y ){
            DFS(e,x );
            //Do sth
        }
    }

    //Do sth

    return;
}


//Djistra
vector <pair<int,int> > vec[size];
int odl[size];

void Djikstra(int x){
    priority_queue <pair<int,int>, vector <pair<int,int> >, greater<pair<int,int> >  > q;
    q.push({0,x});
    for(int i=0; i<size; ++i){
        odl[i] = INT_MAX;
    }
    while(!q.empty()){
        auto e = q.top();
        q.pop();
        if(e.ff == odl[e.ss]){
            for(auto f:vec[e.ss]){
                if(f.ss + e.ff < odl[f.ff]){
                    odl[f.ff] = f.ss + e.ff;
                    q.push({odl[f.ff],f.ff});
                }
            }
        }
    }
    return;
}


// Find and Union
int rep[size];
//rep[i] = i;

int Find(int x){
    if(rep[x] != x) 
        rep[x] = Find(rep[x]);
    return rep[x];
}

void Union(int x,int y){
    x = Find(x);
    y = Find(y);
    rep[x] = y;
    return;
}