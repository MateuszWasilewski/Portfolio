#include <bits/stdc++.h>
#define ss second
#define ff first
#define ll long long
using namespace std;

int N,k;
ll a,b,c;
ll wyn;
pair<ll,int> pot;
vector <pair<ll,ll> > v[1<<17];
priority_queue <pair<ll,ll> > q[1<<17];
priority_queue <pair<ll,ll> > qt;
map <pair<ll,ll>,ll> mapa;
ll cena[1<<17];

pair<ll,int> dfs (int x,int y,ll cost){
    pair <ll,int> d={0,x};
    cena[x]=cost;
    for(int i=0; i<v[x].size(); ++i){
        if(v[x][i].ff!=y){
            d = dfs(v[x][i].ff,x,cost+v[x][i].ss);
            d.ff+=v[x][i].ss;
            q[x].push({d});
        }
    }
    if(!q[x].empty()){
        d=q[x].top();
        d.ss=x;
    }
    return d;
}

void update(int x, ll cost){
    pair <ll,int> d={-cost,x};
    //cout<<"IN "<<x<<" from "<<y<<" cost "<<cost<<"\n";
    if(!q[x].empty()){
        d=q[x].top();
        auto poz = mapa.find({x,d.ss});
        //cout<<poz->second<<"\n";
        update(d.ss,cost+poz->ss);

        q[x].pop();
        if(!q[x].empty()){
            d=q[x].top();
            qt.push({d.ff-cost,x});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>k;
    for(int i=1; i<N; ++i){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
        mapa.insert({{a,b},c});
        mapa.insert({{b,a},c});
        wyn+=2*c;
    }
    qt.push(dfs(1,0,0));
    //cout<<qt.top().ff<<" "<<qt.top().ss;
    
    while(k>0 && !qt.empty()){
        pot=qt.top();
        qt.pop();
        if(pot.ff>0){
            k--;
            wyn-=pot.ff;
            update(pot.ss,cena[pot.ss]);
        }
        else{
            cout<<wyn<<"\n";
            return 0;
        }
    }
    cout<<wyn<<"\n";
    
    return 0;
}

/*
7 3
1 2 5
2 3 11
2 4 2
5 2 6
1 6 1
7 1 1

*/