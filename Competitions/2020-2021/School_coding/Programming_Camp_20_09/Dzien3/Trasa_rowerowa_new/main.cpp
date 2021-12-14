#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,M,a,b,c,d,k;
int x,y,mid;
vector <pair<int,pair<int,int> > > pol[1005];
bitset <2005> visit;
vector <int> now,last;

bool Eukl(int x,bool writes=0){
    if(x==1 && now.size()==M){
        if(writes)
            last=now;
        return 1;
    }
    bool ok=0;
    for(int i=0;i<pol[x].size() && !ok;++i){
        if(!visit[pol[x][i].ss.ss] && pol[x][i].ss.ff<=mid){
            now.push_back(pol[x][i].ss.ss);
            visit[pol[x][i].ss.ss]=1;
            ok = ok | Eukl(pol[x][i].ff,writes);
            now.pop_back();
            visit[pol[x][i].ss.ss]=0;
        }
    }
    return ok;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    x=1;
    y=1;
    for(int i=1;i<=M;++i){
        cin>>a>>b>>c>>d;
        pol[a].push_back({b,{c,i}});
        pol[b].push_back({a,{d,i}});
        y=max(y,max(c,d));
    }
    mid=y;
    bool cool=Eukl(1);
    if(!cool){
        cout<<"NIE\n";
        return 0;
    }
    k=y;
    while(x<=y){
        mid=(x+y)/2;
        cool=Eukl(1);
        if(cool){
            k=min(k,mid);
            y=mid-1;
        }
        else{
            x=mid+1;
        }
    }
    mid=k;
    Eukl(1,1);
    cout<<k<<"\n";
    for(auto e:last){
        cout<<e<<" ";
    }
    cout<<"\n";

}

/*
4 4
1 2 2 4
2 3 3 4
3 4 4 4
4 1 5 4

*/