#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,M, wynik;
int tab[1002][1002];

bitset <1002> used[1002], flowed[1002];
priority_queue <pair<pair<int,bool>,pair<int,int> > > q;
int x,y;
bool done;

bool flow(int a, int b){
    if(tab[x+a][y+b] <= tab[x][y]){
        used[x+a][y+b] =  used[x+a][y+b] || used[x][y];
        return !flowed[x+a][y+b];
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; ++i){
        for(int z=1; z<=M; ++z){
            cin >> tab[i][z];
            if(tab[i][z]>0) used[i][z] = 1;
            else tab[i][z] *= -1;
            q.push({{tab[i][z],used[i][z]},{i,z}});
        }
    }
    while(!q.empty()){
        x = q.top().ss.ff;
        y = q.top().ss.ss;
        q.pop();
        done = 0;
        done |= flow(1,0);
        done |= flow(0,1);
        done |= flow(-1,0);
        done |= flow(0,-1);
        if(!done && used[x][y]) wynik++;
        flowed[x][y] = 1;
    }
    cout << wynik << "\n";


}
/*
6 9
-2 -2 -1 -1 -2 -2 -2 -12 -3
-2 1 -1 2 -8 -12 2 -12 -12
-5 3 1 1 -12 4 -6 2 -2
-5 -2 -2 2 -12 -3 4 -3 -1
-5 -6 -2 2 -12 5 6 2 -1
-4 -8 -8 -10 -12 -8 -6 -6 -4


*/