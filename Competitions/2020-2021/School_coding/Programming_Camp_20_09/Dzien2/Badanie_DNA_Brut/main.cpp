#include <bits/stdc++.h>
#define ff first
#define ss second
#define sz 200001
using namespace std;


int N,Q,a,b,p,k,l=1;

const int half=262144;
int tree[half*2];

vector<pair<pair<int,int>,pair<int,int> > >v[sz];
vector<pair<pair<int,int>,int> > ask[sz];
vector<pair<int,int> >odp;

void dfs(pair<pair<int,int>,pair<int,int> > x){
    int side[half];
    if(x.ff.ff){
        for(int i=x.ss.ff; i<=x.ss.ss; ++i){
            side[i]=tree[i+half];
            tree[i+half]=x.ff.ss;
        }
    }
    for(int i=half-1; i>0; --i){
        tree[i]=max(tree[i*2],tree[i*2+1]);
    }
    for(auto e:ask[x.ff.ff]){
        int ans=0;
        a=e.ff.ff+half;
        b=e.ff.ss+half;
        while(a!=b && a!=b-1){
            if(a%2==0){
                a/=2;
            }
            else{
                ans=max(ans,tree[a]);
                a++;
                a/=2;
            }
            if(b%2==0){
                ans=max(ans,tree[b]);
                b--;
                b/=2;
            }
            else{
                b/=2;
            }
        }
        ans=max(ans,tree[a]);
        if(a!=b){
            ans=max(ans,tree[b]);
        }
        odp.push_back({e.ss,ans});
    }
    for(auto e:v[x.ff.ff]){
        dfs(e);
    }
    for(int i=x.ss.ff; i<=x.ss.ss; ++i){
        tree[i+half]=side[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    for(int i=1;i<=N;++i){
        cin>>a;
        tree[half+i]=a;
    }
    for(int i=0; i^Q; ++i){
        cin>>a;
        if(a){
            cin>>p>>a>>b;
            ask[p].push_back({{a,b},i});
        }
        else{
            cin>>p>>a>>b>>k;
            v[p].push_back({{l,k},{a,b}});
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