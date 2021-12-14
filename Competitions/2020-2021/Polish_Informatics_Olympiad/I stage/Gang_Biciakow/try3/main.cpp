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

int N,Q,M,a,b,c;
char test;
const int half=131072;
int odp[100001];
vector <obj> kr;
vector <pair<int,int> > v[100001];
map <int,int> tree[half*2];


void add(int x,int y,int c){
    auto poz=tree[x].find(y);
    if(poz==tree[x].end())
        tree[x][y]=c;
    else
        poz->second+=c;
    if(tree[x][y]==0)
        tree[x].erase(y);
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

int sum(int cel){
    tree[0].clear();
    int p=0;
    int k=half-1;
    int mid,wh;
    int x=1;
    while(x<half){
        mid=(p+k)/2;
        if(cel <= mid){
            k = mid;
            wh = x*2+1;
        }
        else{
            p = mid+1;
            wh = x*2;
        }

        for(auto e:tree[x]){
            add(0,e.ff,e.ss);
        }
        tree[x].clear();
        for(auto e:tree[0]){
            add(wh,e.ff,e.ss);
        }
        x=wh^1;
    }
    for(auto e:tree[0]){
        add(x,e.ff,e.ss);
    }
    return tree[x].size();
}

void actual(int i){
    for(auto e:kr[i].pt){
        add(e,kr[i].bt,-1);
        add(e,b,1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>Q;
    obj kra;
    kr.push_back(kra);
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
            cout<<sum(odp[a])<<"\n";
        }
        else{
            cin>>a>>b;
            if(kr[a].bt!=b){
                actual(a);
                kr[a].bt=b;
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

5 1 1
1 2 1
2 3 1
3 4 1
4 5 1
Z 5

*/

