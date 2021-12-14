#include <bits/stdc++.h>

#define sz 300001
#define ll long long
using namespace std;

struct pl{
    int p;
    int k;
    ll c;
    pl(int pp, int kk, ll cc){
        p = pp;
        k = kk;
        c = cc;
    }
    ~pl(){
        
    }
};

const int half=524288;
vector <int> stac[sz];
vector <pl> pol;
ll wym[sz];
int N, M, k;
int wyn[sz];
ll tree[half + sz];

void add(int x, int y, ll c){
    x += half;
    y += half;
    while(x<=y){
        if(x%2){
            tree[x] += c;
            x++;
        }
        if(!(y%2)){
            tree[y] += c;
            y--;
        }
        x/=2;
        y/=2;
    }
    return;
}

void addnow(pl &poln, ll c){
    if(poln.p <= poln.k){
        add(poln.p, poln.k, poln.c*c);
    }
    else{
        add(poln.p, M-1, poln.c*c);
        add(0, poln.k, poln.c*c);
    }
    return;
}

ll ask(int x){
    x += half;
    ll wynik = 0;
    while(true){
        wynik += tree[x];
        if(x == 1) return wynik;
        x /= 2;
    }
}

bool asktot(int x){
    ll wynik = 0;
    for(auto e:stac[x]){
        wynik += ask(e);
        if(wynik >= wym[x]) return true;
    }
    return false;
}

void func(int p, int k, int on, queue <int> &q){
    if(p>k) return;

    int mid = (p+k)/2;
    if(mid > on){
        for(int i=on+1; i<=mid; ++i){
            addnow(pol[i], 1);
        }
    }
    else{
        for(int i=on; i>mid; --i){
            addnow(pol[i], -1);
        }
    }
    queue <int> q1,q2;
    int a;
    while(!q.empty()){
        a = q.front();
        q.pop();
        if(asktot(a)){
            wyn[a] = mid;
            q1.push(a);
        }
        else{
            if(p == k && wyn[a] == 0) wyn[a] = -1;
            q2.push(a);
        }
    }
    if(!q1.empty()) func(p, mid-1, mid, q1);
    if(!q2.empty()) func(mid+1, k, mid, q2);

    if(mid > on){
        for(int i=on+1; i<=mid; ++i){
            addnow(pol[i], -1);
        }
    }
    else{
        for(int i=on; i>mid; --i){
            addnow(pol[i], 1);
        }
    }
    return;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a, b, c;

    cin >> N >> M;
    for(int i=0; i<M; ++i){
        cin >> a;
        stac[a-1].push_back(i);
    }
    queue <int> qt;
    for(int i=0; i<N; ++i){
        cin >> wym[i];
        qt.push(i);
    }

    pol.emplace_back(pl(0,0,0));
    cin >> k;
    for(int i=0; i<k; ++i){
        cin >> a >> b >> c;
        pol.emplace_back(pl(a-1,b-1,c));
    }

    func(1, k, 0, qt);

    for(int i=0; i<N; ++i){
        if(wyn[i] == -1) cout << "NIE\n";
        else cout << wyn[i] << "\n";
    }

    return 0;
}
/*
3 5
1 3 2 1 3
10 5 7
3
4 2 4
1 3 1
3 5 2

*/