//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

const ll limit = 1e9;
ll lm;
vector <pair<ll,ll> > prime;
bitset <limit> bt;
ll suma = 0;
ll N,x;
ll p,k;
map <ll,ll> sumy;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    lm = min(N,limit);

    prime.push_back({2,2});
    suma = 2;
    bt[4] = 1;
    sumy[0] = 2;

    for(ll i=3; i<=lm; i+=2){
        if(!bt[i]){
            suma += i;
            prime.push_back({i,suma});
            sumy[suma - i] = i;
        }
        for(auto &e:prime){
            if(e.ff*i > lm) break;
            else bt[e.ff*i] = 1;
        }
    }
    bool ok = 1;
    if(N == 1) ok = 0;
    for(int i=0; i<prime.size() && ok; ++i){
        ok = (N % prime[i].ff);
    }
    if(ok){
        cout << N << " "<< N << "\n";
        return 0;
    }

    for(int i=prime.size()-1; i>=0; --i){
        x = prime[i].ss - N;
        auto poz = sumy.find(x);
        if(poz != sumy.end()){
            cout << poz->ss << " " << prime[i].ff << "\n";
            return 0;
        }
    }
    cout << "NIE\n";
    //cout << prime.size() << " " << suma <<"\n";


    return 0;
}
/*
15

1000000007

100000000

99999999996
*/