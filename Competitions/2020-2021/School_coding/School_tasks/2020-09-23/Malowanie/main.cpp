#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll n,mod=1e9+7;
ll wynik=4;
ll pc=2;

int main(){
    cin>>n;
    n--;
    if(n>0){
        n--;
        wynik*=3;
        while(n){
            if(n % 2){
                wynik= wynik * pc % mod;
            }
            pc= pc * pc % mod;
            n>>=1;
        }
    }  
    cout<<wynik<<"\n";
}