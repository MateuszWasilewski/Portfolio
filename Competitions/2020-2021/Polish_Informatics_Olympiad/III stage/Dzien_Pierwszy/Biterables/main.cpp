//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

int N;
ll d,a,b;
multiset <ll> st;
vector <ll> v;
priority_queue <pair<ll,ll> > q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> d;
    
    cin >> a;
    for(int i=0; i<a; ++i){
        cin >> b;
        b *= 2;
        st.insert(b);
    }
    for(int i=1; i<N; ++i){
        cin >> a;
        for(int i=0; i<a; ++i){
            cin >> b;
            b *= 2;
            v.push_back(b);
            q.push({abs(d - b), b});
        }
    }

    return 0;
}