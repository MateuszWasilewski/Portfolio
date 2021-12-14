//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

ll N,suma;
const int limit = 1e7;
vector <pair<ll,ll> > prime;
unordered_map <ll,bool> mapa;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    prime.push_back({2,2});
    prime.push_back({3,5});
    prime.push_back({5,7});

    for(ll a = 1; a*a < limit; ++a){
        for(ll b = 1; b*b < limit; ++b){
            ll n = (4*a*a) + b*b;
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)){
                auto poz = mapa.insert({n,0}).ff;
                poz->ss ^= 1;
            }
                
            n = (3 * a * a) + (b * b);

            if (n <= limit && n % 12 == 7){
                auto poz = mapa.insert({n,0}).ff;
                poz->ss ^= 1;
            }
            
            n = (3 * a * a) - (b * b);
            
            if (a > b && n <= limit && n % 12 == 11){
                auto poz = mapa.insert({n,0}).ff;
                poz->ss ^= 1;
            }
        }
    }
    for(int r = 5; r*r < limit; ++r){
        auto poz = mapa.find(r);
        for(int i = r*r; i<limit; i += r*r){
            auto poz1 = mapa.find(i);
            if(poz1 != mapa.end())
                poz1->ss = 0;
        }
    }

    for(auto e:mapa){
        if(e.ss){
            prime.push_back({e.ff, 0});
        }
    }
    cout << prime.size() << "\n";

    return 0;
}