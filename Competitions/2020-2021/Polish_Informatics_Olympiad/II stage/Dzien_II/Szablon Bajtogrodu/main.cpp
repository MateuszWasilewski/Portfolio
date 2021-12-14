//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

vector <pair<int,char> > v[2001];
int N,a,b;
char test;
set <string> node[2001];
string word;
vector <int> todo;
map <string,int> mapa;
vector <string> odp;

void DFS(int x, int y){
    todo.push_back(x);
    if(word != ""){
        for(auto e:todo){
            if(node[e].insert(word).ss){
                auto poz = mapa.insert({word,0});
                poz.ff->ss++;
                if(poz.ff->ss == N) odp.push_back(poz.ff->ff);
            }
        }
    }
    for(auto e:v[x]){
        if(e.ff != y){
            word.push_back(e.ss);
            DFS(e.ff, x);
            word.pop_back();
        }
    }
    todo.pop_back();
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=1; i<N; ++i){
        cin >> a >> b >> test;
        v[a].push_back({b,test});
        v[b].push_back({a,test});
    }

    for(int i=1; i<=N; ++i){
        DFS(i,0);
    }

    sort(odp.begin(), odp.end());
    cout << odp.size() << "\n";
    for(auto e: odp){
        cout << e << "\n";
    }

    return 0;
}

/*

13
1 2 A
1 3 A
2 4 B
3 5 B
4 6 A
4 7 A
5 8 A
5 9 A
6 10 B
7 11 B
8 12 B
13 9 B


*/