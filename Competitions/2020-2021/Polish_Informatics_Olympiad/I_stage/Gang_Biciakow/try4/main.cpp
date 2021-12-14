#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

struct obj {
    int bt;
    vector <int> w;
};
struct edge {
    int wynik=0;
    set <int> update;
    map <int,int> use[2];
};

int N,M,Q;
int a,b,c;
int odp[100001];
vector <pair<int,int> > v[100001];
vector <obj> kr;
char test;
const int half=8;
vector <edge > tree;

void add(int x, int i, int bt,int c){
    bool updt=0;
    auto poz=tree[x].use[i].find(bt);
    if(poz==tree[x].use[i].end()){
        tree[x].use[i][bt]=0;
        updt=1;
    }
    tree[x].use[i][bt]+=c;
    if(tree[x].use[i][bt]==0){
        tree[x].use[i].erase(bt);
        updt=1;
    }
    if(updt)
        tree[x].update.insert(bt);
    return;
}

pair<int,int> dfs(int x,int y){
    pair<int,int> d,f;
    c++;
    d.ff=c;
    odp[x]=c;
    for(auto e:v[x]){
        if(e.ff!=y){
            f=dfs(e.ff,x);
            f.ff+=half;
            f.ss+=half;
            while(f.ff<=f.ss){
                if(f.ff%2){
                    kr[e.ss].w.push_back(f.ff);
                    add(f.ff,0,kr[e.ss].bt,1);
                    f.ff++;
                }
                if(!(f.ss%2)){
                    kr[e.ss].w.push_back(f.ss);
                    add(f.ss,0,kr[e.ss].bt,1);
                    f.ss--;
                }
                f.ff/=2;
                f.ss/=2;
            }
        }
    }
    d.ss=c;
    return d;
}

bool IsUp(int x, int bt){
    bool odp=0;
    while(x!=1 && !odp){
        x/=2;
        odp=(tree[x].use[0].find(bt)==tree[x].use[0].end());
    }
    return odp;
}



int ask(int cel){
    int p=0;
    int k=half-1;
    int x=1,opt,mid;
    int wynik=0;
    bool up,use0,use1;
    set <int> update;
    while(x<half*2){
        mid=(p+k)/2;
        for(auto e:update){
            up=0;
            use0=(tree[x].use[0].find(e)!=tree[x].use[0].end());
            use1=(tree[x].use[1].find(e)!=tree[x].use[1].end());
            if(use0 || use1){
                up=IsUp(x,e);
            }
            if(up && use1){
                opt=tree[x].use[1][e];
                add(x,0, e,opt);
                add(x,1, e,-opt);
            }
        }
        wynik+=tree[x].use[0].size();
        for(auto e:tree[x].update){
            update.insert(e);
        }
        tree[x].update.clear();
        if(cel<=mid){
            k=mid;
            x=x*2;
        }
        else{
            p=mid+1;
            x=x*2+1;
        }
    }
    return wynik;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>Q;
    obj kra;
    edge ed;
    for(int i=0; i^half*2; ++i){
        tree.push_back(ed);
    }
    kr.push_back(kra);
    for(int i=1; i^N; ++i){
        cin>>a>>b>>c;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
        kra.bt=c;
        kr.push_back(kra);
    }
    c=-1;
    dfs(1,0);
    for(int i=0; i^Q; ++i){
        cin>>test;
        if(test=='Z'){
            cin>>a;
            cout<<ask(odp[a])<<"\n";
        }
        else{
            cin>>a>>b;
            if(b!=kr[a].bt){
                for(auto e:kr[a].w){
                    tree[e].update.insert(kr[a].bt);
                    add(e, 0, kr[a].bt, -1);
                    kr[a].bt=b;
                    tree[e].update.insert(kr[a].bt);
                    add(e, 0, kr[a].bt, 1);
                }
            }
        }
    }
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