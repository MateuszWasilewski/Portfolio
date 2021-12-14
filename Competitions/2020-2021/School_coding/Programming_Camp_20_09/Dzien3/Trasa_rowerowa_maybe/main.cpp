#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,M,a,b,c,d,k=1;
bool ok;
vector <pair<int,int> > pol[1001];
vector <pair<pair<int,int>,pair<int,int> > >q;
bitset <2001> visit;
vector <int> odw;
bool Eukl(int x,int y){
    if(visit[x]){
        if(x==1 && odw.size()==M){
            cout<<k<<"\n";
            for(int i=0;i<odw.size();++i){
                cout<<odw[i]<<" ";
            }
            cout<<"\n";
            return 1;
        }
        return 0;
    }
    visit[x]=1;
    bool maybe=0;
    for(int i=0;i<pol[x].size() && !maybe;++i){
        if(pol[x][i].ff!=y){
            odw.push_back(pol[x][i].ss);
            maybe = maybe | Eukl(pol[x][i].ff,x);
            odw.pop_back();
        }
    }
    visit[x]=0;
    return maybe;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);
    cin>>N>>M;
    for(int i=1;i<=M;++i){
        cin>>a>>b>>c>>d;
        q.push_back({{c,i},{a,b}});
        q.push_back({{d,i},{b,a}});
    }
    int k1=0;
    sort(q.begin(),q.end());
    while(k1<q.size() && !ok){
        if(k==q[k1].ff.ff){
            pol[q[k1].ss.ff].push_back({q[k1].ss.ss,q[k1].ff.ss});
            k1++;
        }
        else{
            odw.clear();
            ok=Eukl(1,0);
            k=q[k1].ff.ff;
        }
    }
    if(!q.empty() && !ok){
        ok=Eukl(1,0);
    }
    if(!ok){
        cout<<"NIE\n";
    }
    return 0;
}

/*
4 4
1 2 2 4
2 3 3 4
3 4 4 4
4 1 5 4

*/