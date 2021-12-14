#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N, wynik,a ,b ;
vector <int> vec[50001];
bitset <50001> visit;
unordered_set <int> st;

pair<int,int> change;
int wn;


int DFS(int x, int y){
    int suma = 0;
    int maxi = 0,c,y2;
    for(auto e:vec[x]){
        if(st.find(e) != st.end() && e != y){
            c = DFS(e,x);
            if(c > maxi){
                y2 = e;
                maxi = c;
            }
            suma += c;
        }
    }
    if(N-suma-1 > maxi){
        maxi = N-suma-1;
        y2 = y;
    }
    if(maxi < wn){
        wn = maxi;
        change = {y2,x};
    }
    return suma + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; ++i) st.insert(i);
    for(int i=1; i<N; ++i){
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    b = 1;
    while(N>1){
        wn = INT32_MAX;
        DFS(b,0);
        wynik++;
        st.erase(change.ss);
        b = change.ff;
        N = wn;
    }
    cout << wynik << "\n";
    return 0;
}
/*
5
1 2
2 3
4 3
5 3

*/