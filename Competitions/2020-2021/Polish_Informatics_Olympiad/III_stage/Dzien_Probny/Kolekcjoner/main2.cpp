//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

int N, k;
ll a,b,maxi;
map <ll, int> mapa;
priority_queue <ll> q;
vector <pair<ll,ll> > v;
const ll limit= 5e5;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> a >> b;
        maxi = __gcd(maxi,b);
        if(mapa.find(a) == mapa.end()){
            mapa[a] = 0;
            q.push(a);
        }
        v.push_back({a,b});
    }
    if(maxi >= limit){
        cout << maxi << "\n";
        return 0;
    }

    while(q.top() != 1){
        auto e = q.top();
        k = mapa[e];
        if(k == N){
            cout << e << "\n";
            return 0;
        }
        a = __gcd(e, v[k].ff);
        b = __gcd(e, v[k].ss);

        if(a != e && b != e){
            mapa.erase(e);
            q.pop();
        }
        auto poz = mapa.find(a);
        if(poz != mapa.end()){
            poz->ss = max(poz->ss, k+1);
        }
        else{
            mapa[a] = k+1;
            q.push(a);
        }

        poz = mapa.find(b);
        if(poz != mapa.end()){
            poz->ss = max(poz->ss, k+1);
        }
        else{
            mapa[b] = k+1;
            q.push(b);
        }
    }
    cout << "1\n";

    return 0;
}
/*
4
5 7
10 15
13 20
7 5


*/