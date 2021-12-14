#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a,b,N;
vector <int> pol[100001];
vector <ll> pod[100001];
ll wynik[100001];

int dfs(int x,int y){
    ll d,sum=0;
    for(auto e:pol[x]){
        if(e!=y){
            d=dfs(e,x);
            sum+=d;
            pod[x].push_back(d);
        }
    }
    pod[x].push_back(N-sum-1);
    for(auto e:pod[x]){
        wynik[x]+=(N-1-e)*e;
    }
    return sum+1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=1; i^N; ++i){
        cin>>a>>b;
        pol[a].push_back(b);
        pol[b].push_back(a);
    }
    dfs(1,0);
    for(int i=1; i<=N; ++i){
        cout<<wynik[i]/2<<"\n";
    }


}

/*
6
3 2
2 5
2 1
2 4
2 6

*/