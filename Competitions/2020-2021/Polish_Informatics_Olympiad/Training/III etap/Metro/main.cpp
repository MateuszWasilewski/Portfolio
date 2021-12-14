#include <bits/stdc++.h>
#define ff first
#define ss second
#define sz 3000010
using namespace std;

int N,k;
int a ,b, wynik;
vector <int> vec[sz];
queue < pair<int,int> > q;
bitset <sz> bt;
int licz[sz];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> k;
    for(int i=1; i<N; ++i){
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for(int i=1; i<=N; ++i){
        if(vec[i].size() == 1){
            q.push({1,i});
        }
        licz[i] = vec[i].size();
    }

    while((q.size() > k || q.front().ff == wynik) && q.size()>2 ){
        auto f = q.front();
        q.pop();
        wynik = f.ff;
        bt[f.ss] = 1;

        for(auto e:vec[f.ss]){
            if(!bt[e]){
                licz[e]--;
                if(licz[e] == 1){
                    q.push({f.ff+1, e});
                }
            }
        }
    }
    cout << wynik << " " << q.size() << "\n";
    while(!q.empty()){
        cout << q.front().ss << " ";
        q.pop();
    }
    cout << "\n";
    return 0;
}
/*
8 3
1 5
2 5
2 7
3 7
4 5
5 6
7 8

*/