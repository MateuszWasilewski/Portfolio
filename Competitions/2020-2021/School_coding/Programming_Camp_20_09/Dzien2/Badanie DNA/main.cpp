#include <bits/stdc++.h>
#define ff first
#define ss second
#define sz 200001
using namespace std;


int N,Q,a,b,p,k,l=1;

const int half=262144;
vector <pair<int,int > > tree[half*2];
map <int,int> mapa;
vector<pair<pair<int,int>,pair<int,int> > >v[sz];
vector<pair<pair<int,int>,int> > ask[sz];
vector<pair<int,int> >odp;

void add(int x,int c,int comp){
    for(int i=0; i^tree[x].size();++i){
        if(tree[x][i].ff>comp){
            tree[x][i].ss+=c;
        }
    }
    if(x==1)
        return;
    else
        add(x/2,c,comp);
}

int treedown(int x, int l, int p, int ll, int pp){
    if(!tree[x].empty()){
        if(tree[x][tree[x].size()-1].ss==0){
            return tree[x][tree[x].size()-1].ff;
        }
    }
    auto poz=mapa.find(x);
    if(poz!=mapa.end())
        return poz->second;

    int ans=0;
    if((l+p)/2>=ll)
        ans=max(ans,treedown(x*2,l,(l+p)/2,ll,pp));
    if((l+p+1)/2<=pp)
        ans=max(ans,treedown(x*2+1,(l+p+1)/2,p,ll,pp));
    if(l>=ll && p<=pp){
        mapa[x]=ans;
    }
    return ans;
}

void dfs(pair<pair<int,int>,pair<int,int> > x){
    if(x.ff.ff){
        a=x.ss.ff+half;
        b=x.ss.ss+half;
        while(a!=b && a!=b-1){
            if(a%2){
                tree[a].push_back({x.ff.ss,0});
                add(a/2,1,x.ff.ss);
                a++;
            }
            if(!(b%2)){
                tree[b].push_back({x.ff.ss,0});
                add(b/2,1,x.ff.ss);
                b--;
            }
            a/=2;
            b/=2;
        }
        tree[a].push_back({x.ff.ss,0});
        add(a/2,1,x.ff.ss);
        if(a!=b){
            tree[b].push_back({x.ff.ss,0});
            add(b/2,1,x.ff.ss);
        }
    }
    mapa.clear();
    for(auto e:ask[x.ff.ff]){
        odp.push_back({e.ss,treedown(1,0,half-1,e.ff.ff,e.ff.ss)});
    }
    for(auto e:v[x.ff.ff])
        dfs(e);

    if(x.ff.ff){
        a=x.ss.ff+half;
        b=x.ss.ss+half;
        while(a!=b && a!=b-1){
            if(a%2){
                tree[a].pop_back();
                add(a/2,-1,x.ff.ss);
                a++;
            }
            if(!(b%2)){
                tree[b].pop_back();
                add(b/2,-1,x.ff.ss);
                b--;
            }
            a/=2;
            b/=2;
        }
        tree[a].pop_back();
        add(a/2,-1,x.ff.ss);
        if(a!=b){
            tree[b].pop_back();
            add(b/2,-1,x.ff.ss);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    for(int i=0;i^N;++i){
        cin>>a;
        tree[half+i].push_back({a,0});
    }
    for(int i=0; i^Q; ++i){
        cin>>a;
        if(a){
            cin>>p>>a>>b;
            ask[p].push_back({{a-1,b-1},i});
        }
        else{
            cin>>p>>a>>b>>k;
            v[p].push_back({{l,k},{a-1,b-1}});
            l++;
        }
    }
    dfs({{0,0},{0,0}});
    sort(odp.begin(),odp.end());
    for(auto e:odp){
        cout<<e.ss<<"\n";
    }
    return 0;
}

/*
6 7
3 5 2 4 6 3
1 0 2 4
0 0 1 3 7
0 0 3 5 1
1 1 3 6
1 2 2 5
0 1 2 4 3
1 3 2 6

*/