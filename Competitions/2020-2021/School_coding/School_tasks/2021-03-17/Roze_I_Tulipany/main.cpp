#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll N,k;
ll mod = 1e9 + 7;
ll pot = 2;
ll wynik = 1;
int main(){
    cin >> N >> k;

    k--;
    while(k > 0){
        if(k % 2){
            wynik = wynik * pot % mod;
        }
        pot = pot * pot % mod;
        k/=2;
    }
    cout << wynik << "\n";
}