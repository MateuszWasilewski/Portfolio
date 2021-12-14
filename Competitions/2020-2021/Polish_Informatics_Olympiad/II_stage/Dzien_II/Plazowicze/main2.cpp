//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

int N,t;
ll X,k;
ll sk = 1073741824;
ll odp,m;

priority_queue <pair<ll,pair<ll,ll> > >q,q1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a,b;
    cin >> N >> X >> t;
    cin >> a;
    a *= sk;
    for(int i=1; i<N; ++i){
        cin >> b;   
        b *= sk;
        q.push({b-a,{-a,1}});
        a = b;
    }
    for(int i=0; i<t; ++i){
        cin >> k;
        q1 = q;
        while(k>0){
            auto e = q1.top();
            q1.pop();
            if(e.ss.ss < k){
                k -= e.ss.ss;
                q1.push({e.ff/2,{e.ss.ff,e.ss.ss*2}});
            }
            else{
                odp = -e.ss.ff + (k-1)*e.ff + e.ff/2; 
                k = 0;
            }
        }
        m = sk;
        while(odp%2 == 0 && m >1){
            odp/=2;
            m/=2;
        }
        cout << odp << "/" << m << "\n";

    }

    return 0;
}

