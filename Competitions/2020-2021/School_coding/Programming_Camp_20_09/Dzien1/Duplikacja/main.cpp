#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N,M,a,b;
ll mod=1e9+696969;
vector <ll> v(1,0);
vector <ll> pol[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;++i){
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i^M;++i){
        cin>>a>>b;
        pol[a].push_back(b);
        pol[b].push_back(a);
    }
    for(int i=1;i<=N;++i){
        cout<<v[i]<<" ";
        for(int z=0;z^pol[i].size();++z){
            if(pol[i][z]>i){
                v[pol[i][z]]=(v[pol[i][z]]+v[i])%mod;
            }
        }
    }
    cout<<"\n";

    return 0;
}