#include <bits/stdc++.h>

using namespace std;

int N, a, b, k, wynik;
vector <int> v[300001];
int odp[300001];

void dfs(int x, int y){
    odp[x] = 0;
    for(auto e:v[x]){
        if(e != y){
            dfs(e, x);
            odp[x] += odp[e] + 1;
        }
    }
    odp[x] = max(0, odp[x] - k);
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<N; ++i){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    a = 1;
    b = N;
    while(true){
        k = (a+b)/2;
        dfs(1,0);
        
        if(odp[1] == 0){
            wynik = k;
            b = k-1;
        }
        else if(odp[1]>0){
            a = k+1;
        }
        if(a > b) break;
    }
    cout << wynik << "\n";
}

/*
7
1 2
1 3
2 5
2 6
7 2
4 1
*/