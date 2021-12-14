//Gang Biciakow
//Mateusz Wasilewski
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

struct node{
    int wynik=0;
    unordered_map <int,int> mapa;
    unordered_map <int,int> below;
};
struct  kraw {
    int biciak=0;
    pair <int,int> pk;
};

const int half=131072;
int odp[100007];
int N, M, Q;
int a,b,c;
int k_i=-1;
char test;


vector <pair<int,int> > v[100007];
vector <kraw> kr;
node tree[half*2];
vector <pair<int,int> > Add;

//Funkcje wykonywalne
void kr_op(int x, int p, int k, int i, bool add, bool found=0);
void actual(int x, int y, int bt, bool add);
pair<int,int> dfs(int x, int y);
int ans(int x);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    kraw kra;
    kr.push_back(kra);

    cin>>N>>M>>Q;
    for(int i=1; i^N; ++i){
        cin>>a>>b>>c;
        v[a].push_back({b,i});
        v[b].push_back({a,i});

        kra.biciak=c;
        kr.push_back(kra);
    }

    dfs(1,0);

    for(int i=0; i^Q; ++i){
        cin>>test;
        if(test=='Z'){
            cin>>a;
            cout<<ans(half + odp[a])<<"\n";
        }
        else{
            cin>>a>>b;
            if(kr[a].biciak != b){
                kr_op(1, 0, half-1, a, 0, 0);
                kr[a].biciak = b;
                kr_op(1, 0, half-1, a, 1, 0);
            }
        }
    }
    return 0;
}

// Deklaracje Funkcji
pair<int,int> dfs(int x, int y){
    pair<int,int> d;
    k_i++;
    odp[x]=k_i;
    d.ff=k_i;
    for(auto e:v[x]){
        if(e.ff!=y){
            kr[e.ss].pk = dfs(e.ff,x);
            kr_op(1, 0, half-1, e.ss, 1, 0);
        }
    }
    d.ss=k_i;
    return d;
}

void kr_op(int x, int p, int k, int i, bool add, bool found){
    int bt = kr[i].biciak;
    int pp = kr[i].pk.ff;
    int kk = kr[i].pk.ss;

    {
        auto poz = tree[x].below.find(bt);
        if(poz==tree[x].below.end()) poz = tree[x].below.insert({bt,0}).ff;

        if(add) poz->second++;
        else poz->second--;
        if(poz->second == 0) tree[x].below.erase(poz->first);
    }

    if(pp<=p && k<=kk){
        auto poz = tree[x].mapa.find(bt);
        if(poz==tree[x].mapa.end()) poz = tree[x].mapa.insert({bt,0}).ff;

        if(add) poz->ss++;
        else poz->ss--;
        
        if(!found){
            if(add && poz->ss==1){
                tree[x].wynik++;
                if(x<half) actual(x, x, bt, add);
            }
            else if(!add && poz->ss==0){
                tree[x].wynik--;
                if(x<half) actual(x, x, bt, add);
            }
        }

        if(poz->ss == 0) tree[x].mapa.erase(poz->ff);
        return;
    }

    if(!found) found = (tree[x].mapa.find(bt)!=tree[x].mapa.end());

    int mid = (p+k)/2;
    if(pp<=mid) kr_op(x*2, p, mid, i, add, found);
    if(kk>=mid+1) kr_op(x*2+1, mid+1, k, i, add, found);
    return;
}

void actual(int x, int y, int bt, bool add){
    if(x!=y){
        if(tree[x].mapa.find(bt)!=tree[x].mapa.end()){
            if(add) tree[x].wynik--;
            else tree[x].wynik++;
            return;
        }
    }

    if(tree[x*2].below.find(bt) != tree[x*2].below.end()) actual(x*2, y, bt, add);
    if(tree[x*2+1].below.find(bt) != tree[x*2+1].below.end()) actual(x*2+1, y, bt, add);
    return;
}

int ans(int x){
    int wynik = tree[x].wynik;
    while(x){
        x/=2;
        wynik += tree[x].wynik;
    }
    return wynik;
}