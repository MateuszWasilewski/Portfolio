#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,a,wynik=1,r;
vector <int> v;
map <int,short> mapa[5001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i^N;++i){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();++i){
        for(int z=0;z<i;++z){
            r=v[i]-v[z];
            auto poz=mapa[z].find(r);
            if(poz==mapa[z].end()){
                wynik=max(wynik,2);
                mapa[i][r]=2;
            }
            else{
                wynik=max(poz->ss+1,wynik);
                mapa[i][r]=poz->ss +1;
                mapa[z].erase(poz->ff);
            }

        }
    }
    cout<<wynik<<"\n";
    return 0;
}