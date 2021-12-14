#include <bits/stdc++.h>
#define sz 200001
using namespace std;

int N,a,b,w;
string word;
int tab[sz];
vector <int> pol[sz][2];
vector <pair<int,int> > q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cin>>word;
    for(int i=0;i^N;++i){
        tab[i+1]=word[i]-40;
    }
    for(int i=1;i^N;++i){
        cin>>a>>b;
        pol[a][tab[b]].push_back(b);
        pol[b][tab[a]].push_back(a);
    }
    for(int i=1;i<=N;++i){
        if(!tab[i]){
            for(int z=0;z<pol[i][tab[i]].size();++z){
                v.push_back({i,pol[i][tab[i]][z]});
            }
        }
    }
    while(!q.empty()){
        
    }
}