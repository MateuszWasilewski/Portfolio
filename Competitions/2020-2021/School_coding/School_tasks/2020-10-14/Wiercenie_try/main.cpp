#include <bits/stdc++.h>

using namespace std;

int N,a;
int tab[2001][2001];

int dfs(int p, int k){
    if(tab[p][k]==0){
        tab[p][k]=INT32_MAX;
        for(int i=p; i<=k; ++i){
            int sum=0;
            if(i>p)
                sum= max(sum, dfs(p,i-1));
            
            if(i<k)
                sum= max(sum, dfs(i+1,k));
            tab[p][k]=min(tab[p][k], tab[i][i] + sum);
        }
    }
    return tab[p][k];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>a;
        tab[i][i]=a;
    }
    cout<<dfs(0,N-1)<<"\n";
}
/*
4
8 24 12 6

*/