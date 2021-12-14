//Gang Biciakow
//Mateusz Wasilewski
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

class obj {
public:
    int biciak=0;
    int p=0;
    int k=0;
};

int N,Q,M,a,b,c;
char test;
const int half=131072;
int odp[100001];
vector <obj> kr;
vector <pair<int,int> > v[100001];
map <int,int> tree[half*2];

pair<int,int> dfs(int x,int y){
    pair<int,int> d,f;
    c++;
    d.ff=c;
    odp[x]=c;
    for(auto e:v[x]){
        if(e.ff!=y){
            f=dfs(e.ff,x);
            kr[e.ss].p=f.ff;
            kr[e.ss].k=f.ss;
        }
    }
    d.ss=c;
    return d;
}

void add(int x,int y){
    auto poz=tree[x].find(y);
    if(poz==tree[x].end())
        tree[x][y]=1;
    else
        tree[x][y]++;
    return;
}

void erase(int x,int y){
    auto poz=tree[x].find(y);
    if(poz==tree[x].end()){
        cout<<"XD?\n";
    }
    else{
        tree[x][y]--;
        if(tree[x][y]==0)
            tree[x].erase(y);
    }
    return;
}

void sum(int x){
    set <int> suma;
    while(true){
        for(auto e:tree[x]){
            suma.insert(e.ff);
        }
        if(x==1)
            break;
        x/=2;
    }
    cout<<suma.size()<<"\n";
}

void actual(int i, bool ad){
    int x=kr[i].p+half;
    int y=kr[i].k+half;
    while(x<=y){
        if(x%2){
            if(ad)
                add(x,kr[i].biciak);
            else
                erase(x,kr[i].biciak);
            x++;
        }
        if(!(y%2)){
            if(ad)
                add(y,kr[i].biciak);
            else
                erase(y,kr[i].biciak);
            y--;
        }
        x/=2;
        y/=2;
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
        kra.biciak=c;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
        kr.push_back(kra);
    }
    c=-1;
    dfs(1,0);
    for(int i=1; i^N; ++i){
        actual(i,1);
    }
    for(int i=0; i^Q; ++i){
        cin>>test;
        if(test=='Z'){
            cin>>a;
            sum(half+odp[a]);
        }
        else{
            cin>>a>>b;
            if(kr[a].biciak!=b){
                actual(a,0);
                kr[a].biciak=b;
                actual(a,1);
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

