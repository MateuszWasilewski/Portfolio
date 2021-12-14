#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,X,Q,t,a;
int tab[100003];
map <int,set<int>> mapa;
set <int> st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>X>>Q;
    auto poz=mapa.begin();
    for(int i=1; i<=N; ++i){
        cin>>t;
        for(int z=0; z^t; ++z){
            cin>>a;
            poz=mapa.find(a);
            if(poz==mapa.end()){
                mapa[a]=st;
            }
            mapa[a].insert(i);
        }
    }
    for(auto poz1=mapa.rbegin(); poz1!=mapa.rend(); poz1++){
        for(auto e:poz1->ss){
            if(e==N){
                tab[e]++;
            }
            else{
                tab[e]=min(tab[e]+1,tab[e+1]);
                poz=mapa.find(poz1->ff-1);
                if(poz==mapa.end()){
                    tab[e+1]=tab[e];
                }
                else if(mapa[poz1->ff-1].find(e+1)==mapa[poz1->ff-1].end()){
                    tab[e+1]=tab[e];
                }
            }
        }
    }
    for(int i=0; i^Q; ++i){
        cin>>a;
        cout<<tab[a]<<"\n";
    }
    return 0;
}

/*
3 9 3
1 6
2 3 8
2 5 7
3
2
1

*/