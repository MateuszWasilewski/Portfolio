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
ll a,b;
map <ll, int> mapa;
priority_queue <ll> q;
vector <pair<ll,ll> > v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    cin >> a >> b;
    mapa[a] = 0;
    mapa[b] = 0;
    q.push(a);
    q.push(b);
    v.push_back({a,b});
    for(int i=1; i<N; ++i){
        cin >> a >> b;
        v.push_back({a,b});
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