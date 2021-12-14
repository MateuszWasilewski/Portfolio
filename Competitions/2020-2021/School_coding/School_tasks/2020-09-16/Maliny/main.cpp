#include <bits/stdc++.h>
using namespace std;
int tab[1001][1001];
int N,M,k,a,wynik;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>k;
    for(int i=1;i<=N;++i){
        for(int z=1;z<=M;++z){
            cin>>a;
            tab[i][z]=tab[i-1][z]+tab[i][z-1]-tab[i-1][z-1]+a;
            if(i>=k&& z>=k){
                wynik=max(wynik,tab[i][z]-tab[i-k][z]-tab[i][z-k]+tab[i-k][z-k]);
            }
        }
    }
    cout<<tab[N][M]-wynik<<"\n";
}