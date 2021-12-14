#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

class pros{
public:
    int x1,x2,y1,y2;
};

const int half=262144;
int wynik=0;
int tree[half*2];
int N,w,h,k=half;
vector <pair<pair<int,int>,pair<int,int>>> v;
vector <int> kol;
vector <pros> aside;
map <int,int> mapa;

void add(int x,int y,int c){
    while(x<=y){
        if(x%2){
            tree[x]+=c;
            x++;
        }
        if(!(y%2)){
            tree[y]+=c;
            y--;
        }
        x/=2;
        y/=2;
    }
}

int sum(int x){
    int ans=tree[x];
    if(x!=1)
        ans+=sum(x/2);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x,y;
    pros pro;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>x>>y>>w>>h;
        pro.x1=x;
        pro.x2=x+w;
        pro.y1=y;
        pro.y2=y+h;
        aside.push_back(pro);
        kol.push_back(y);
        kol.push_back(y+h);
    }
    sort(kol.begin(),kol.end());
    auto poz=mapa.end();
    for(auto e:kol){
        poz=mapa.find(e);
        if(poz==mapa.end()){
            mapa[e]=k;
            k++;
        }
    }
    kol.clear();
    for(auto e:aside){
        v.push_back({{e.x1,1},{mapa[e.y1],mapa[e.y2]}});
        v.push_back({{e.x2,-1},{mapa[e.y1],mapa[e.y2]}});
    }
    sort(v.begin(),v.end());
    for(auto e:v){
        add(e.ss.ff,e.ss.ss,e.ff.ss);
        if(e.ff.ss==1){
            if(sum(e.ss.ff)%2)
                wynik++;
        }
    }
    cout<<wynik<<"\n";
}

/*

9
0 0 16 14
1 1 8 5
2 2 4 3 
11 1 3 7
1 7 8 6
2 8 4 4
3 9 2 2
10 9 5 4
11 10 3 2


*/
