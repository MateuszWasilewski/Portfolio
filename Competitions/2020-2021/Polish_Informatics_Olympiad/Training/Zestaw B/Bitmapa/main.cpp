#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int tab[184][184];
int N,M,c;
pair<int,int> pr;
string line;
queue <pair<pair<int,int>,int> > q;

void func(int x, int y){
    if(tab[pr.ff+x][pr.ss+y] > c){
        tab[pr.ff+x][pr.ss+y] = c;
        q.push({{pr.ff+x,pr.ss+y},c});
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; ++i){
        cin >> line;
        for(int z=0; z<M; ++z){
            if(line[z] == '1'){
                tab[i+1][z+1] = 0;
                q.push({{i+1,z+1},0});
            }
            else tab[i+1][z+1] = 1000;
        }
    }
    while(!q.empty()){
        pr = q.front().ff;
        c = q.front().ss + 1;
        q.pop();
        func(1,0);
        func(0,1);
        func(-1,0);
        func(0,-1);
    }
    for(int i=1; i<=N; ++i){
        for(int z=1; z<=M; ++z){
            cout << tab[i][z] << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*
3 4
0001
0011
0110


*/