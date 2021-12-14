#include <bits/stdc++.h>
#define ff first
#define ss second
#define sz 14
using namespace std;

vector <pair<int,pair<int,char> > > v[sz];
int N,a,b,c,znak;
struct node {
    unordered_map <char,int> mapa;
    set <int> kr;
};
int kr[sz];
int suma;
vector <node> trie;
string word;
set <string> ans;

void DFS(int x, int y, int pos){
    for(auto e:trie[pos].kr){
        if(kr[e] == 0) suma++;
        kr[e]++;
    }
    if(suma)

    for(auto e:v[x]){
        if(e.ff != y){
            auto f = trie[pos].mapa.insert({e.ss.ss,trie.size()});
            word.push_back(e.ss.ss);
            DFS(e.ss.ff, x, f.ff->ss);
            word.pop_back();
        }
    }
    for(auto e:trie[pos].kr){
        kr[e]++;
        if(kr[e] == 0) suma--;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=1; i<N; ++i){
        cin >> a >> b >> znak;
        v[a].push_back({b,{i,znak}});
        v[b].push_back({a,{i,znak}});
    }
}