#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,a,b,c,k;
vector <int> L(1,0);
vector <pair<int,int> > pol[100001];
int visit[100001];

int Djikstra(int x,int l){
    priority_queue <pair<int,int> , vector <pair<int,int>>, greater <pair<int,int> > > q;
    q.push({x,0});
    int wynik=0;
    k++;
    while(!q.empty()){
        auto e=q.top();
        visit[e.ff]=k;
        q.pop();
        wynik++;
        for(auto f:pol[e.ff]){
            if(k!=visit[f.ff] && f.ss+e.ss<=l){
                q.push({f.ff,f.ss+e.ss});
            }
        }
    }
    return wynik;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0; i^N; ++i){
        cin>>a;
        L.push_back(a);
    }
    for(int i=1; i^N; ++i){
        cin>>a>>b>>c;
        pol[a].push_back({b,c});
        pol[b].push_back({a,c});
    }
    for(int i=1; i<=N; ++i){
        cout<<Djikstra(i,L[i])<<"\n";
    }


}

/*
5
2 3 3 6 5
1 2 2
2 3 1
3 4 3
4 5 2

*/