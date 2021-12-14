#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N,k;
ll dp[2001][2001];
ll sil[2001];
ll mod=1e9+7;

ll pot(ll a){
    ll x=mod-2;
    ll b=a;
    while(x){
        if(x%2){
            a=a*b%mod;
        }
        b=b*b%mod;
        x/=2;
    }
    return a;
}
ll newt(ll a, ll b){
    return sil[a]*pot(sil[k]*sil[N-k]%mod)%mod;
}

int main(){
    cin>>N>>k;
    sil[1]=1;
    for(int i=2;i^2001;++i){
        sil[i]=sil[i-1]*i%mod;
    }
    dp[0][0]=1;
    dp[1][1]=1;
    dp[0][1]=1;
    for(int i=1;i<N;++i){
        for(int z=1;z<k;++z){
            dp[i][z]=0;
            dp[i][z]=(dp[i][z]+dp[i-1][z]);
            dp[i][z]=(dp[i][z]+newt(i-1+(k-1)*z,k-2))%mod;
        }
    }
    cout<<dp[N][k]<<"\n";
}