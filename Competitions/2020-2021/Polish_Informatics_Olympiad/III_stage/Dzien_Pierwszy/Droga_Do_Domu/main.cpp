//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

int N,M,s,k,a,b,l;
ll t,c,x,y;
map <pair<int,int>,ll> mapa[10007];
map <pair<int,int>, ll> drogi;
struct obj
{
    int v = 0;
    int bus;
    ll coile = 0;
    ll tdrogi = 0;
    ll tpierw = 0;
};


priority_queue <pair<pair<ll,int> ,pair<int,int> >, vector <pair<pair<ll,int>,pair<int,int>> >, greater<pair<pair<ll,int>,pair<int,int>> >  > q;

vector < obj> v[10007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> s >> k >> t;
    for(int i=0; i<M; ++i){
        cin >> a >> b >> c;
        drogi[{a,b}] = c;
        drogi[{b,a}] = c;
    }
    mapa[1][{0,-1}] = t;
    q.push({{t, -1},{1,0}});
    for(int i=1; i<=s; ++i){
        cin >> l >> x >> y;
        obj ob;
        ob.bus = i;
        ob.tpierw = x;
        ob.coile = y;
        cin >> a;
        for(int z=1; z<l; ++z){
            cin >> b;
            ob.v = b;
            auto poz = drogi.find({a,b});
            ob.tdrogi = poz->ss;
            v[a].push_back(ob);
            a = b;
            ob.tpierw += poz->ss;
        }
    }
    while(!q.empty()){
        auto e = q.top();
        q.pop();
        if(e.ss.ff == N){
            cout << e.ff.ff << "\n";
            return 0;
        }
        
        if(mapa[e.ss.ff][{e.ss.ss,e.ff.ss}] == e.ff.ff){
            for(auto f:v[e.ss.ff]){
                auto now = e;
                if(now.ss.ss != f.bus){
                    now.ff.ss++;
                    now.ss.ss = f.bus;
                    if(now.ff.ss > k) continue;
                }

                ll czas = (e.ff.ff - f.tpierw + f.coile - 1)/f.coile;
                if(czas < 0) czas = 0;
                czas = f.tpierw + czas * f.coile;
                now.ff.ff = czas + f.tdrogi;

                auto poz = mapa[f.v].find({f.bus,now.ff.ss});
                if(poz != mapa[f.v].end()){
                    if(poz->ss <= now.ff.ff){
                        continue;
                    }
                }

                now.ss.ff = f.v;
                mapa[f.v][{f.bus,now.ff.ss}] = now.ff.ff;
                q.push(now);
            }
        }
    }
    cout << "NIE\n";
    return 0;
}
/*
4 4 2 1 1
1 2 2
2 3 4
1 3 3
4 3 2
4 0 10
1 2 3 4
3 2 7
1 3 2


*/