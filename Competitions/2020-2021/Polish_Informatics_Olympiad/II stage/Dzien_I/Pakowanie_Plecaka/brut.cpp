//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

int odp[1001];
int N,a,k, suma;
int total;
vector <int> items;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i=1; i<=N; ++i){
        odp[i] = INT32_MAX;
        cin >> a;
        total += a;
        items.push_back(a);
    }
    for(int i=1; i<=total; ++i){
        suma = i;
        k = 0;
        for(auto e:items){
            if(suma >= e){
                suma -= e;
                k++;
                odp[k] = min(odp[k],i);
            }
        }
    }
    for(int i=1; i<=N; ++i){
        cout << odp[i] << " ";
    }
    cout << "\n";

    return 0;
}