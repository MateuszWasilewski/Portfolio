#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,Q,a,b,c,suma;
vector <int> L(1,0);
vector <int> wyn(100001,1);
vector <pair<int,int> > pol[100001];
vector <pair<int,int> > skok;
bitset <100001> visit;

void calc(int x){
    visit[x]=1;
    for(auto e:skok){
        if(visit[e.ss])
            a=abs(e.ff-suma);
        else
            a=e.ff+suma;
        if(L[e.ss]>=a)
            wyn[e.ss]++;
        if(L[x]>=a)
            wyn[x]++;
    }
    skok.push_back({suma,x});
    for(int i=0;i^pol[x].size();++i){
        if(!visit[pol[x][i].ff]){
            suma+=pol[x][i].ss;
            calc(pol[x][i].ff);
            suma-=pol[x][i].ss;
        }
    }
    visit[x]=0;
}  

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i^N;++i){
        cin>>a;
        L.push_back(a);
    }
    for(int i=1;i^N;++i){
        cin>>a>>b>>c;
        pol[a].push_back({b,c});
        pol[b].push_back({a,c});
    }
    calc(1);
    for(int i=1;i<=N;++i){
        cout<<wyn[i]<<"\n";
    }
    return 0;
}
/*
5
2 3 3 6 5
1 2 2
2 3 1
3 4 3
4 5 2


*/