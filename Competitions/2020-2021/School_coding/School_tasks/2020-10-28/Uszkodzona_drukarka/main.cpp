#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,wynik,now,x;
string in;
vector <string> word;
vector <pair<int,int> > line;
map <char,int> mapa;
vector <pair<int,map<char,int> > > v;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.push_back({0,mapa});
    auto poz=v[0].ss.end();
    for(int i=0; i^N; ++i){
        cin>>in;
        word.push_back(in);
        line.push_back({in.size(),i});
    }
    sort(line.begin(),line.end());
    for(int i=0; i^N; ++i){
        in=word[line[i].ss];
        x=0;
        now=0;
        for(int z=0; z<in.size(); ++z){
            poz=v[x].ss.find(in[z]);
            now+=v[x].ff;
            if(poz==v[x].ss.end()){
                v[x].ss[in[z]]=v.size();
                v.push_back({0,mapa});
            }
            x=v[x].ss[in[z]];
        }
        v[x].ff++;
        wynik=max(wynik,now+1);
    }
    cout<<wynik<<"\n";

    return 0;
}
/*
4
oig
oi
omg
om

6
d
dr
dru
druk
drukarka
kartka

*/