#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N,k;
const int half = 1048576;
ll a, mod = 1e9+7;
ll tree[half*2];
ll wynik;

void update(int x){
    x += half;
    tree[x]++;
    while(x>0){
        if(x < half) tree[x] = tree[x*2] * tree[x*2+1] % mod;
        x/=2;
    }
    return;
}

ll ask(int x, int y){
    x += half;
    y += half;
    ll odp = 1;
    while(x <=  y){
        if(x%2){
            odp = odp * tree[x] % mod;
            x++;
        }
        if(!(y%2)){
            odp = odp * tree[y] % mod;
            y--;
        }
        x/=2;
        y/=2;
    }
    return odp;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> k;
    for(int i=0; i<N; ++i){
        cin >> tree[half + i];
    }
    for(int i = half-1; i>0; --i){
        tree[i] = tree[i*2] * tree[i*2+1] % mod;
    }
    for(int i=0; i<N; ++i){
        wynik = (wynik + ask(max(0,i-k),i)) % mod;
        update(i);
    }
    cout << wynik << "\n";
}

/*
6 3
6 5 4 3 2 1

5 2
3 5 7 0 1
*/