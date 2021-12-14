#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
    ll wynik = 0;
    ll a = 0;
    ll r = 0;
    ll k = 1;
};
struct maszt{
    ll a = 0;
    ll r = 0;
};

const int half = 524288;
vector <node> tree;
vector <maszt> maszty;
node clear;
maszt blank;
int N,M;
char test;

ll calculate(int x){
    tree[x].wynik = (2 * tree[x].a + (tree[x].k-1) * tree[x].r) * tree[x].k / 2;
    if(x<half) tree[x].wynik += tree[x*2].wynik + tree[x*2+1].wynik;
    return tree[x].wynik;
}

ll ask(int x, int a, int b, int l, int p, ll a1, ll r){
    bool ok = 0;
    ll wynik = 0;
    if(a <= l && p <= b){
        tree[x].a += a1 + (l-a) * r;
        tree[x].r += r;
        ok = 1;
    }
    else{
        if(tree[x].a != 0 || tree[x].r != 0){
            tree[x*2].a += tree[x].a;
            tree[x*2].r += tree[x].r;

            tree[x*2+1].a += tree[x].a + tree[x*2].k * tree[x].r;
            tree[x*2+1].r += tree[x].r;

            calculate(x*2);
            calculate(x*2+1);
            tree[x].a = 0;
            tree[x].r = 0;
        }

        int mid = (l+p)/2;
        if(a <= mid) wynik += ask(x*2, a, b, l, mid, a1,r);
        if(b > mid) wynik += ask(x*2+1, a, b, mid+1, p, a1, r);

    }

    calculate(x);
    if(ok) wynik = tree[x].wynik;

    return wynik;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll x, a, b, r;


    cin >> N >> M;
    for(int i=0; i<=N; ++i) maszty.push_back(blank);
    for(int i=0; i<half*2; ++i) tree.push_back(clear);
    for(int i=half-1; i>0; --i) tree[i].k = tree[i*2].k + tree[i*2+1].k;

    for(int i=0; i<M; ++i){
        cin >> test;
        if(test == 'P'){
            cin >> x >> a >> r;

            maszty[x].a = a;
            maszty[x].r = r;
            a = maszty[x].a / maszty[x].r;
            r = maszty[x].a % maszty[x].r;
            if(a > 0) ask(1,x-a, x-1, 0, half-1, r, maszty[x].r);
            ask(1,x, x+a, 0, half-1, maszty[x].a, -maszty[x].r); 
        }
        else if(test == 'Z'){
            cin >> a >> b;
            x = ask(1, a, b, 0, half-1, 0, 0);
            r = b - a + 1;
            cout << x / r << "\n";
        }
        else{
            cin >> x;

            a = maszty[x].a / maszty[x].r;
            r = maszty[x].a % maszty[x].r;
            if(a > 0) ask(1,x-a, x-1, 0, half-1, -r, -maszty[x].r);
            ask(1,x, x+a, 0, half-1, -maszty[x].a, maszty[x].r); 
            maszty[x].a = 0;
            maszty[x].r = 0;
        }
    }
    return 0;
}
/*
11 7
P 5 30 10
Z 6 7
P 10 22 5
Z 6 7
Z 6 6
U 5
Z 6 6


*/