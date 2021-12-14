#include <bits/stdc++.h>
#define ff first
#define ss second
#define sz 200007
#define ll long long
using namespace std;

int N,M,k,a,b;
vector <int> v[sz];
bitset <sz> bt;
priority_queue <int> q;

int dfs(int x){
    bt[x] = 1;
    int wn = 1;
    for(auto e:v[x]){
        if(!bt[e]){
            wn += dfs(e);
        }
    }
    return wn;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> k;
    for(int i=0; i<M; ++i){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=N; ++i){
        if(!bt[i]){
            a = dfs(i);
            q.push(a);
        }
    }
    while(q.size()>1 && k > 0){
        auto e = q.top();
        q.pop();
        auto f = q.top();
        q.pop();
        q.push(e+f);
        k--;
    }
    ll odp = 0, now;
    while(!q.empty()){
        now = q.top();
        q.pop();
        odp += now*(now-1)/2;
    }
    cout << odp << "\n";
}