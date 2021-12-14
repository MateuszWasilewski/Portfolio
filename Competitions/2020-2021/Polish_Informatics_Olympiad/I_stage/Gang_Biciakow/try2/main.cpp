//Gang Biciakow
//Mateusz Wasilewski
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,M,Q,a,b,c,k=-1;
int op=0;
char test;
const int half=131072;
const int size=100001;
int tab[size];
vector <pair<int,int> > v[size];
vector <pair<int,pair<int,int> > > kr (1,{0,{0,0}});
map <int,int> tree[half*2];

pair<int,int> dfs(int x, int y){
    pair<int,int> d,e;
    k++;
    d.ff=k;
    tab[x]=k;
    for(auto i:v[x]){
        if(i.ff!=y){
            e=dfs(i.ff, x);
            kr[i.ss].ss=e;
        }
    }
    d.ss=k;
    return d;
}

void change(int x, pair<int,int> bt){
    //op++;
    auto poz=tree[x].find(bt.ff);
    if(poz==tree[x].end()){
        tree[x][bt.ff]=0;
    }
    tree[x][bt.ff]+=bt.ss;
    if(tree[x][bt.ff]==0){
        tree[x].erase(bt.ff);
    }
    return;
}

void add(int x, int y, pair<int,int> bt){
    x+=half;
    y+=half;
    while(x<=y){
        if(x%2){
            change(x, bt);
            x++;
        }
        if(!(y%2)){
            change(y, bt);
            y--;
        }
        x/=2;
        y/=2;
    }
}

void Find(int x, int cel, int p, int k){
    if(p==k)
        return;
    for(auto e:tree[x]){
        change(x*2, e);
        change(x*2+1, e);
    }
    tree[x].clear();
    int mid=(p+k)/2;
    if(cel<=mid)
        Find(x*2, cel, p, mid);
    else
        Find(x*2+1, cel, mid+1, k);
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>Q;
    for(int i=1; i^N; ++i){
        cin>>a>>b>>c;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
        kr.push_back({c,{0,0}});
    }
    dfs(1,0);
    for(int i=1; i^N; ++i){
        add(kr[i].ss.ff,kr[i].ss.ss, {kr[i].ff,1});
    }
    for(int i=0; i^Q; ++i){
        cin>>test;
        if(test=='Z'){
            cin>>a;
            Find(1, tab[a], 0, half-1);
            //cout<<tree[tab[a]+half].size()<<"\n";
        }
        else{
            cin>>a>>b;
            if(kr[a].ff!=b){
                add(kr[a].ss.ff, kr[a].ss.ss, {kr[a].ff,-1});
                kr[a].ff=b;
                add(kr[a].ss.ff, kr[a].ss.ss, {kr[a].ff,1});
            }
        }
    }
    cout<<op<<"\n";
    return 0;
}

/*
6 3 5
1 2 3
1 3 2
3 4 3
5 3 1
6 4 2
Z 5
Z 6
B 2 1
Z 5
Z 6

*/