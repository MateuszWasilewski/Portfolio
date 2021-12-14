#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N,k;
ll dp[100000];
ll wynik=1;

int main(){
    cin>>N>>k;
    dp[1]=1;
    dp[k]=1;
    for(int i=2;i<=N;++i){
        dp[i]+=dp[i-2];
        if(i-k-1>0)
            dp[i]+=dp[i-k-1];
        wynik+=dp[i];
    }
    cout<<wynik<<"\n";
}