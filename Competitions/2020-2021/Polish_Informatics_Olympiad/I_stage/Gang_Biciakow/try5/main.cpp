//Gang Biciakow
//Mateusz Wasilewski
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

class obj {
public:
    int bt=0;
    vector <int> pt;
};
class mp {
public:
    int up;
    int now;
    set <int> down;
};
class node {
public:
    int wynik;
    map <int,mp> mapa;
};
mp nmap;

int N,Q,M,a,b,c;
char test;
int odp[100001];
const int half=131072;

vector <obj> kr;
vector <pair<int,int> > v[100001];
vector <node> tree;

pair <int,int> dfs(int x, int y);

void add(int x, int bt, int c);

int ans(int x);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    obj kra;
    node nd;
    nd.wynik=0;
    nd.mapa.clear();
    kr.push_back(kra);
    for(int i=0; i^half*2; ++i){
        tree.push_back(nd);
    }

    cin>>N>>M>>Q;
    for(int i=1; i^N; ++i){
        cin>>a>>b>>c;
        kra.bt=c;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
        kr.push_back(kra);
    }
    c=-1;
    dfs(1,0);
    for(int i=0; i^Q; ++i){
        cin>>test;
        if(test=='Z'){
            cin>>a;
            cout<<ans(odp[a]+half)<<"\n";
        }
        else{
            cin>>a>>b;
            if(kr[a].bt!=b){
                for(auto e:kr[a].pt){
                    add(e,kr[a].bt,-1);
                    add(e,b,1);
                }
                kr[a].bt=b;
            }
        }
    }
    return 0;
}

void add(int cel, int bt, int c){
    int x=cel;
    auto poz=tree[x].mapa.find(bt);
    if(poz==tree[x].mapa.end()){
        tree[x].mapa[bt]=nmap;
        poz=tree[x].mapa.find(bt);
        x/=2;
        while(x){
            auto poz1=tree[x].mapa.find(bt);
            if(poz1!=tree[x].mapa.end()){
                if(poz1->ss.now>0){
                    poz->ss.up++;
                }
            }
            x/=2;
        }
    }
    x=cel;
    if(poz->ss.now==0 && poz->ss.now+c==1){
        if(tree[x].mapa[bt].up==0){
            tree[x].wynik++;
        }
        for(auto e:poz->ss.down){
            auto poz1=tree[e].mapa.find(bt);
            if(poz1->ss.up==0 && poz1->ss.now>0){
                tree[e].wynik--;
            }
            poz1->ss.up++;
        }
        x/=2;
        while(x){
            auto poz1=tree[x].mapa.find(bt);
            if(poz1==tree[x].mapa.end()){
                tree[x].mapa[bt]=nmap;
                poz1=tree[x].mapa.find(bt);
            }
            poz1->ss.down.insert(cel);
            x/=2;
        }
    }
    else if(poz->ss.now==1 && poz->ss.now+c==0){
        if(tree[x].mapa[bt].up==0){
            tree[x].wynik--;
        }
        for(auto e:poz->ss.down){
            auto poz1=tree[e].mapa.find(bt);
            poz1->ss.up--;
            if(poz1->ss.up==0 && poz1->ss.now>0){
                tree[e].wynik++;
            }
        }
        x/=2;
        while(x){
            auto poz1=tree[x].mapa.find(bt);
            poz1->ss.down.erase(cel);
            if(poz1->ss.down.empty() && poz1->ss.now==0){
                tree[x].mapa.erase(poz1->ff);
            }
            x/=2;
        }
    }
    poz->ss.now+=c;
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
                    kr[e.ss].pt.push_back(f.ff);
                    add(f.ff,kr[e.ss].bt,1);
                    f.ff++;
                }
                if(!(f.ss%2)){
                    kr[e.ss].pt.push_back(f.ss);
                    add(f.ss,kr[e.ss].bt,1);
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

int ans(int x){
    int odp=0;
    while(x){
        odp+=tree[x].wynik;
        x/=2;
    }
    return odp;
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

5 1 1
1 2 1
2 3 1
3 4 1
4 5 1
Z 5

*/

