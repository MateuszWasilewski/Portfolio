//Gra Platformowa
//Mateusz Wasilewski
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

const int sz=100002;
int N,X,Q,a,t;
pair<int,int> d;
int tab[sz];
vector <int> v[sz];
priority_queue <pair<int,int> > q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>X>>Q;
    for(int i=1; i<=N; ++i){
        cin>>t;
        for(int z=0; z^t; ++z){
            cin>>a;
            v[i].push_back(a);
        }
        if(!v[i].empty())
            q.push({v[i][v[i].size()-1],i});
    }
    while(!q.empty()){
        d=q.top();
        q.pop();
        v[d.ss].pop_back();
        if(!v[d.ss].empty()){
            q.push({v[d.ss][v[d.ss].size()-1],d.ss});
        }
        if(d.ss==N){
            tab[d.ss]++;
        }
        else{
            tab[d.ss]=min(tab[d.ss]+1,tab[d.ss+1]);
            if(!v[d.ss+1].empty()){
                if(v[d.ss+1][v[d.ss+1].size()-1]!=(d.ff-1)){
                    tab[d.ss+1]=tab[d.ss];
                }
            }
            else{
                tab[d.ss+1]=tab[d.ss];
            }
            
        }
    }
    for(int i=0; i^Q; ++i){
        cin>>a;
        cout<<tab[a]<<"\n";
    }
    return 0;
}