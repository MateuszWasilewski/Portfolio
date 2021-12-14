#include <bits/stdc++.h>

using namespace std;

const int limit = 100010;

set <int> st[limit];
vector <int> v[limit];
bitset <limit> vs;
string now, goal;


bool dfs(int x, char k) {
    
    bool ok = 0;
    if (k == now[x - 1])
        return 1;

    for (int i = 0; !ok && i < v[x].size(); i++) {
        if (now[v[x][i] - 1] == k) {
            ok = 1;
            now[x - 1] = k;
        }
    }
    vs[x] = 1;
    if (!ok) {
        for (auto &e:st[x]) {
            if (!vs[e]) {
                ok = dfs(e, k);
                if (ok) {
                    now[x - 1] = k; 
                    break;
                }
            }
        }
    }
    
    vs[x] = 0;
    return ok;
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    int N, a, b;
    queue <int> rozp;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> N;
        cin >> now >> goal;
        bool result = 1;
        for (int z = 1; z <= N; z++) {
            st[i].clear();
            v[i].clear();
        }

        for (int z = 1; z < N; z++) {
            cin >> a >> b;
            st[a].insert(b);
            st[b].insert(a);
        }

        
        for (int z = 1; z <= N; z++) {
            if (st[z].size() == 1)
                rozp.push(z);
        }

        while (!rozp.empty()) {
            a = rozp.front();
            rozp.pop();
            result &= dfs(a, goal[a - 1]);
            if (!st[a].empty()) {
                int e = *st[a].begin();
                st[e].erase(a);
                st[a].erase(e);
                v[e].push_back(a);
                v[a].push_back(e);
                if (st[e].size() == 1)
                    rozp.push(e);   
            }
        }

        cout << (result && (now == goal) ? "TAK\n" : "NIE\n");
    }
}
/*
1
8
11000100
10110100
2 1
3 1
4 3
5 3
6 3
7 6
8 2

*/