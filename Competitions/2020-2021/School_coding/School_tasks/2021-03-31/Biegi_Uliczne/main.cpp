#include <bits/stdc++.h>
#define ff first
#define ss second
#define sz 1000010

using namespace std;
int N, M, a,b,wynik;
vector <int> v[sz];
bitset <sz> used;
bitset <sz> start;
int st[sz];
queue <int> q;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i=1; i<N; ++i){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> M;
    for(int i=0; i<M; ++i){
        cin >> a;
        start[a] = 1;
    }

    for(int i=1; i<=N; ++i){
        st[i] = v[i].size();
        if(st[i] == 1) q.push(i);
    }

    while(!q.empty()){
        a = q.front();
        q.pop();
        if(used[a]) continue;
        for(auto e:v[a]){
            if(!used[e]){
                if(start[a]){
                    if(start[e]){
                        used[e] = 1;
                        wynik++;
                    }
                    else{
                        start[e] = 1;
                    }
                }
                st[e]--;
                if(st[e] == 1 && !used[e]) q.push(e);
            }
        }
    }
    cout << wynik << "\n";
}
/*
5
1 2
3 2
4 1
1 5
4
1 2 5 4


*/