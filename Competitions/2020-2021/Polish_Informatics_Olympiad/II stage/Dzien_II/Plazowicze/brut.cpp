//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

int N,z;
ll X,a,b,k,mln=1073741824;
ll mid;
priority_queue <pair<ll,pair<ll,ll> > > q,q1; 

void read(){
    auto e = q.top();
    mid = (-e.ss.ff+e.ss.ss)/2;
    a = mln;
    while(mid % 2 == 0 && a>1){
        mid/=2;
        a/=2;
    }
    cout << mid << "/" << a << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> X >> z;
    cin >> a;
    a *= mln;
    for(int i=1; i<N; ++i){
        cin >> b;
        b *= mln;
        q1.push({b-a,{-a,b}});
        a = b;
    }
    for(int i=0; i<z; ++i){
        q = q1;
        cin >> k;
        k--;
        while(k>0){
            auto e = q.top();
            k--;
            //read();
            q.pop();
            mid = (-e.ss.ff+e.ss.ss)/2;
            q.push({e.ff/2,{-mid,e.ss.ss}});
            q.push({e.ff/2,{e.ss.ff,mid}});
        }
        read();
    }

    return 0;
}
/*
5 10 1
0 2 3 7 10
8

2 10 5
0 10
1
2
3
4
5



*/