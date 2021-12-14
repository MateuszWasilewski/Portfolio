//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;


const int half = 524288;
int N;
ll a;
struct node{
    ll wynik = 0;
    ll mini = 0;
    ll add = 0;
};
node tree[half*2];
priority_queue <pair<ll,int> > q;
list <ll> odp;
ll suma;

void actual(int x){
    while(x>0){
        if(x < half) tree[x].mini = min(tree[x*2].wynik, tree[x*2+1].wynik);
        tree[x].wynik = tree[x].mini + tree[x].add;
        x/=2;
    }
    return;
}

void add(int x,int y, int c){
    x += half;
    y += half;
    while(x <= y){
        if(x%2){
            tree[x].add += c;
            actual(x);
            x++;
        }
        if(!(y%2)){
            tree[y].add += c;
            actual(y);
            y--;
        }
        x/=2;
        y/=2;
    }
}

void search(int x, ll add){
    if(tree[x].wynik + add >= 0) return;

    if(x >= half){
        q.push({-tree[x].mini, x-half});
        tree[x].mini = 0;
        tree[x].wynik = tree[x].mini + tree[x].add;
        return;
    }
    add += tree[x].add;
    if(tree[x*2].wynik + add < 0) search(x*2, add);
    if(tree[x*2+1].wynik + add < 0) search(x*2+1, add);

    tree[x].mini = min(tree[x*2].wynik, tree[x*2+1].wynik);
    tree[x].wynik = tree[x].mini + tree[x].add;
    return;    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> a;
        add(0, i-1, a);
        suma += a;
        tree[i+half].mini = -a;
    }
    for(int i=half*2-1; i>0; --i){
        if(i<half) tree[i].mini = min(tree[i*2].wynik,tree[i*2+1].wynik);
        tree[i].wynik = tree[i].mini + tree[i].add;
    }
    odp.push_front(suma);
    while(odp.size()<N){
        search(1,0);
        auto e = q.top();
        q.pop();
        suma -= e.ff;
        odp.push_front(suma);
        add(0, e.ss-1, -e.ff);
    }
    for(auto e:odp){
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}

/*
6
10 8 3 30 5 10


*/