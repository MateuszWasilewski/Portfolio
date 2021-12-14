#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define sz 3100
using namespace std;


ll N,t,a,b,c,d;
pair<ll,ll> wynik[sz];
char test;

void read(ll x, ll y){
    for(ll i=2; i<=y; ++i){
        while(x % i == 0 && y % i == 0){
            x/=i;
            y/=i;
        }
    }
    cout << x << "/" << y << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> t;
    for(int i=1; i<=N; ++i){
        cin >> wynik[i].ff;
    }
    for(int i=0; i<t; ++i){
        cin >> test;
        if(test == 'U'){
            cin >> a >> b >> c;
            while(a <= b){
                if(wynik[a].ff < c) wynik[a].ss++;
                if(wynik[a].ff > c) wynik[a].ss--;
                wynik[a].ff = c;
                a++;
            }
        }
        else if(test == 'D'){
            cin >> a >> b >> c;
            if(c != 0){
                d = abs(c)/c;
                while(a <= b){
                    wynik[a].ss += d;
                    wynik[a].ff += c;
                    a++;
                }
            } 
        }
        else if(test == 'S'){
            ll odp = 0;
            cin >> a >> b;
            c = b - a +1;
            while(a <= b){
                odp += wynik[a].ff;
                a++;
            }
            read(odp, c);
        }
        else{
            ll odp = 0;
            cin >> a >> b;
            c = b - a +1;
            while(a <= b){
                odp += wynik[a].ss;
                a++;
            }
            read(odp, c);
        }
    }
    return 0;
}
/*
5 8
1 3 5 4 2
D 2 5 -1
S 1 4
U 2 3 3
Z 1 5
D 4 5 3
U 3 4 5
Z 1 5
S 2 5



*/