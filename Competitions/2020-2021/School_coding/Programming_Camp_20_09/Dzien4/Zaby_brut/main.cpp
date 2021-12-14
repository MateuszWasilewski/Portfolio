#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,M,px,py,kx,ky,wx,wy,Q;

int tab[1005][1005];
vector <pair<int,int> > v;

void calc(int a, int b){
    tab[a][b]=INT_MAX;
    for(auto e:v){
        tab[a][b]=min(tab[a][b],abs(a-e.ff)+abs(b-e.ss));
    }
}

int Djikstra(){
    pair<int,int> a,b,d;
    priority_queue <pair<int,pair<int,int> > > q;
    a={px,py};
    b={kx,ky};
    q.push({0,a});
    while(!q.empty()){
        auto c=q.top();
        q.pop();
        a=c.ss;
        if(a==b){
            return c.ff;
        }
        if(a.ff>1 && tab[a.ff-1][a.ss]==0){
            calc(a.ff-1,a.ss);
            q.push({max(c.ff,tab[a.ff-1][a.ss]),{a.ff-1,a.ss}});
        }
        if(a.ff<N && tab[a.ff+1][a.ss]==0){
            calc(a.ff+1,a.ss);
            q.push({max(c.ff,tab[a.ff+1][a.ss]),{a.ff+1,a.ss}});
        }
        if(a.ss>1 && tab[a.ff][a.ss-1]==0){
            calc(a.ff,a.ss+1);
            q.push({max(c.ff,tab[a.ff][a.ss-1]),{a.ff,a.ss-1}});
        }
        if(a.ss<M && tab[a.ff][a.ss+1]==0){
            calc(a.ff,a.ss+1);
            q.push({max(c.ff,tab[a.ff][a.ss+1]),{a.ff,a.ss+1}});
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    cin>>px>>py>>kx>>ky;
    cin>>Q;
    for(int i=0; i^Q; ++i){
        cin>>wx>>wy;
        tab[wx][wy]=-1;
        v.push_back({wx,wy});
    }
    cout<<Djikstra()<<"\n";
    return 0;

}

/*
5 5
1 1 5 5
2
3 3
4 2

*/