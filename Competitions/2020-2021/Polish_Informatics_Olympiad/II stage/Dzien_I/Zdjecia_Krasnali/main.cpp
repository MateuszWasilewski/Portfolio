//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

int N,M;
int a,b,k;
const int sz = 10;//500010;
vector <int> vec[sz];
int odp[sz];
int done[sz];
queue <int> q;
bool ok;

void solve(int x){
    //if(done[x] != vec[x].size()/2) return;

    if(odp[x] == 0){
        odp[x] = k;
        k++;
    }
    for(auto e:vec[x]){
        done[e]++;
        if(done[e] == vec[e].size()/2) q.push(e);
    }
    return;
}


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
    ok = (vec[1].size() > 0 && vec[2].size() > 0);

    odp[1] = 1;
    odp[2] = N;
    k = 2;
    done[1] = vec[1].size()/2;
    q.push(1);
    while(!q.empty() && ok){
        solve(q.front());
        q.pop();
    }
    for(int i=1; i<=N; ++i){
        if(odp[i] == 0 && vec[i].size() > 0) ok = 0;
        else if(odp[i] == 0){
            odp[i] = k;
            k++;
        }
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