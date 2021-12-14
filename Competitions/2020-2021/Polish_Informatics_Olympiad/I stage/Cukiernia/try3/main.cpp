//Cukiernia
//Mateusz Wasilewski
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
using namespace std;

int N,k=0;
ll a,b,c,mini;
ll wynik=0;
ll suma[3];
bool ok;
vector <pair<ll,int> > v[3];
vector <ll> cheap;
queue <pair<ll,vector<int> > > q;
vector <ll> bestway;
vector <int> pusty;
pair<ll,vector<int> > e;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>a>>b>>c;
        mini=min(b+c,min(a+c,a+b));
        wynik+=mini;
        suma[0]+=a;
        suma[1]+=b;
        suma[2]+=c;
        cheap.push_back(mini);
        v[0].push_back({b+c-mini,i});
        v[1].push_back({a+c-mini,i});
        v[2].push_back({a+b-mini,i});
    }
    for(int i=0; i<3;++i)
        sort(v[i].begin(),v[i].end());

    
    q.push({0,pusty});
    for(int i=0;i<3;++i){
        if(suma[i]!=0){
            k++;
            while(q.front().ss.size()!=k){
                for(int z=0;z<3;++z){
                    e=q.front();
                    ok=1;
                    for(auto f:e.ss){
                        if(v[i][z].ss==f)
                            ok=0;
                    }
                    if(ok){
                        e.ss.push_back(v[i][z].ss);
                        e.ff+=v[i][z].ff;
                        q.push(e);
                    }
                }
                q.pop();
            }
        }
    }
    mini=LLONG_MAX;
    while(!q.empty()){
        mini=min(mini,q.front().ff);
        q.pop();
    }
    cout<<wynik+mini<<"\n";
    return 0;
}

/*
5
5 1 1
0 3 4
1 4 3
4 0 0
0 0 0

6
859144 808737 320851
893878 219175 191174
372717 898484 551612
985075 147257 295022
883767 81925 394020
874887 136811 427001

4343581

*/