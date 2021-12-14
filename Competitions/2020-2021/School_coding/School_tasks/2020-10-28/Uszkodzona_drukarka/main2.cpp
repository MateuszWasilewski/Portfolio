#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,a,wynik;
string word;
vector <string> v;
map <string,int> mapa;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i^N; ++i){
        cin>>word;
        v.push_back(word);
    }
    sort(v.begin(),v.end());
    auto poz=mapa.end();
    for(int i=0; i^N; ++i){
        word.clear();
        a=0;
        for(int z=0; z<v[i].size(); ++z){
            word+=v[i][z];
            poz=mapa.find(word);
            if(poz!=mapa.end()){
                a=max(a,poz->ss);
            }
        }
        if(poz==mapa.end()){
            mapa[word]=a+1;
        }
        else{
            poz->ss++;
        }
        wynik=max(wynik,mapa[word]);
    }
    cout<<wynik<<"\n";
    return 0;
}