#include <bits/stdc++.h>

using namespace std;
int N,M,Q,a,b,k;
vector <int> v[1001];
int gr[1001];

void dfs(int x){
    gr[x]=k;
    for(auto e:v[x]){
        if(gr[e]==0){
            dfs(e);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=0;i<M;++i){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=N;++i){
        if(gr[i]==0){
            k++;
            dfs(i);
        }
    }
    cin>>Q;
    for(int i=0;i<Q;++i){
        cin>>a>>b;
        if(gr[a]==gr[b])
            cout<<"1";
        else
            cout<<"0";
        
    }
    cout<<"\n";
}
/*
9 9
1 2
3 4
5 6
7 8
9 5
7 2
8 2
6 9
1 7
3
1 8
6 2
4 7

*/