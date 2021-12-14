//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

int N,M,a,b,k;
const int sz = 500010;
vector <int> vec[sz];
queue <int> q;
int odp[sz];
int done[sz];
bool ok = 1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<M; ++i){
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    odp[1] = 1;
    odp[2] = N;
    k = 2;
    for(int i=3; i<=N; ++i){
        if(vec[i].size() == 0){
            odp[i] = k;
            k++;
        }
    }

    q.push(1);
    while(!q.empty()){
        a = q.front();
        q.pop();
        if(odp[a] == 0){
            odp[a] = k;
            k++;
        }
        if(a != 2){
            for(auto e:vec[a]){
                done[e]++;
                if(done[e] == vec[e].size()/2) q.push(e);
            }
        }
    }
    
    for(int i=1; i<=N && ok; ++i){
        if(odp[i] == 0) ok = 0;
    }
    if(ok){
        cout << "TAK\n";
        for(int i=1; i<=N; ++i){
            cout << odp[i] << " ";
        }
        cout << "\n";
    }
    else cout << "NIE\n";

    return 0;
}


/*
6 7
5 6
1 4
4 5
5 3
1 5
3 2
2 6

3 3
1 2
2 3
3 1

*/