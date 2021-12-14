//Mieszanie Kolorow
//Mateusz Wasilewski
#include <bits/stdc++.h>

using namespace std;

int N,M;
int a,b,c,wynik;
const int half=1048576;
int tree[half*2];

void add(int x, int y, int k);
int ask(int x);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0; i^M; ++i){
        cin >> a >> b >> c;
        add(a-1, b-1, 1<<(c-1));
    }
    for(int i=0; i^N; ++i){
        wynik += (ask(i) == 3);
    }
    cout << wynik << "\n";
    return 0;
}

int ask(int x){
    x += half;
    int k = 0;
    while(true){
        k |= tree[x];
        if(x==1) break;
        x/=2;
    }
    return k;
}

void add(int x, int y, int k){
    x += half;
    y += half;
    while(x<=y){
        if(x%2){
            tree[x] |= k;
            x++;
        }
        if(!(y%2)){
            tree[y] |= k;
            y--;
        }
        x/=2;
        y/=2;
    }
    return;
}