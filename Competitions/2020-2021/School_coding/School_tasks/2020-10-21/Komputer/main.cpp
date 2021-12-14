#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;

int N,k;
ll a,b,p;
ll with;
ll nwith;
vector <pair<ll,int> > v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>a>>b;
        v.push_back({a,1});
        v.push_back({b,-1});
    }
    sort(v.begin(),v.end());
    for(auto e:v){
        if(k==0){
            nwith=max(nwith,e.ff-p);
            p=e.ff;
        }
        else if(k>0 && k+e.ss==0){
            with=max(with, e.ff - p +1);
            p=e.ff+1;
        }
        k+=e.ss;
    }
    nwith=max(nwith,8640000-p +1);
    cout<<nwith<<"\n";
    cout<<with<<"\n";
}
/*
9 
30000 35000 
10000 20000 
15000 16000 
40000 44000 
77000 220000
13000 41000 
60000 67000 
50000 55000 
65000 70000

*/