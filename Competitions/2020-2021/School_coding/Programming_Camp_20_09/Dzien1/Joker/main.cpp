#include <bits/stdc++.h>
#define sz 200001
#define ff first
#define ss second
using namespace std;

int N,M,Q;
int a,b;
double c,d;
vector <pair<int,int> > pol[sz];
set <set<double> > v;
vector <set<double> > vc;
set<double> st[sz];
bitset <sz> visit;
set <double> s;
void dfs(int x,int y){
    visit[x]=1;
    st[x]=s;
    for(int i=0;i<pol[x].size();++i){
        if(!visit[pol[x][i].ff]){
            s.insert(pol[x][i].ss);
            dfs(pol[x][i].ff,x);
            s.erase(pol[x][i].ss);
        }
        else if(pol[x][i].ff!=y){
            s.insert(pol[x][i].ss);
            if((s.size()-st[pol[x][i].ff].size())%2 && (s.size()-st[pol[x][i].ff].size())>2){
                set<double> mt;
                for(auto poz=s.begin();poz!=s.end();++poz){
                    if(st[pol[x][i].ff].find(*poz)==st[pol[x][i].ff].end()){
                        mt.insert(*poz);
                    }
                }
                v.insert(mt);
            }
            s.erase(pol[x][i].ss);
        }
    }
    visit[x]=0;
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin>>N>>M>>Q;
    for(int i=0;i^M;++i){
        cin>>a>>b;
        pol[a].push_back({b,i+1});
        pol[b].push_back({a,i+1});
    }
    dfs(1,0);
    //cout<<"\n";
    for(auto poz=v.begin();poz!=v.end();poz++){
        vc.push_back(*poz);
        /*for(auto poz1=vc[vc.size()-1].begin();poz1!=vc[vc.size()-1].end();poz1++){
            cout<<*poz1<<" ";
        }
        cout<<"\n";*/
    }
    //cout<<"\n";
    for(int i=0;i^Q;++i){
        cin>>c>>d;
        bool ok=1;
        for(int z=0;z^v.size() && ok;++z){
            vc[z].insert(c-0.5);
            vc[z].insert(d+0.5);
            auto poz1=vc[z].find(c-0.5);
            auto poz2=vc[z].find(d+0.5);
            poz2--;
            ok=(poz1!=poz2);
            vc[z].erase(c-0.5);
            vc[z].erase(d+0.5);
        }
        if(ok){cout<<"NIE\n";}
        else{cout<<"TAK\n";}
    }

}

/*
6 8 2
1 3
1 5
1 6
2 5
2 6
3 4
3 5
5 6
4 8
4 7
*/