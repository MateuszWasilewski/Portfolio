//Gra Platformowa
//Mateusz Wasilewski
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
int N,X,Q,a,b;
int odp[1000001];
vector <pair<int,int> > v;

bool comp(pair<int,int> x,pair<int,int> y){
    return (x.ff>=y.ff);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>X>>Q;
    for(int i=1; i<=N; ++i){
        cin>>a;
        for(int z=0; z^a; ++z){
            cin>>b;
            v.push_back({b,i});
        }
    }
    sort(v.begin(), v.end(), comp);
    for(int i=0; i^v.size(); ++i){
        a=v[i].ss;
        if(a==N)
            odp[a]++;
        else{
            odp[a]=min(odp[a]+1,odp[a+1]);
            odp[a+1]=odp[a];
        }
    }
    for(int i=0; i^Q; ++i){
        cin>>a;
        cout<<odp[a]<<"\n";
    }
    return 0;
}