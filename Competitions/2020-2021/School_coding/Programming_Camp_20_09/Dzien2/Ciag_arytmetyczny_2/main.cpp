#include<bits/stdc++.h>
#define ff first
#define ss second
#define sh short
using namespace std;

int N,a,wynik=1,k;
vector <int> v;
vector <sh> pol[5001];
bitset <5001> visit;
priority_queue <pair<int,pair<sh,sh> > >q;
void dfs(int x,int depth){
    visit[x]=1;
    wynik=max(wynik,depth);
    for(auto e:pol[x]){
        dfs(e,depth+1);
    }
}

void calc(){
    for(int i=0;i<N;++i){
        if(!visit[i]){
            dfs(i,1);
        }
    }
    visit=0;
    for(int i=0;i<N;++i){
        pol[i].clear();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i^N;++i){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0;i^v.size();++i){
        for(int z=i+1;z^v.size();++z){
            q.push({v[z]-v[i],{i,z}});
        }
    }
    while(!q.empty()){
        if(k==q.top().ff){
            pol[q.top().ss.ff].push_back(q.top().ss.ss);
            q.pop();
        }
        else{
            k=q.top().ff;
            calc();
        }
    }
    calc();
    cout<<wynik<<"\n";

    return 0;
}