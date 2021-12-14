#include <bits/stdc++.h>
#define sz 1001
using namespace std;

int n,m,a,b;
int tab[sz][sz];
bool ok[sz][sz];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; ++i){
        cin>>a;
        for(int z=0; z<a; ++z){
            cin>>b;
            ok[i][b]=1;
        }
    }
    for(int i=1; i<=n; ++i){
        for(int z=1; z<=m; ++z){
            tab[i][z]=max(tab[i-1][z-1]+ok[i][z],max(tab[i-1][z],tab[i][z-1]));
        }
    }
    cout<<tab[n][m]<<"\n";

    return 0;
}
/*
4 3
2 2 1
1 1
1 3
1 3

5 6
3 1 2 3
0
2 2 4
1 4
2 5 6

4 4
1 4
1 2
1 3
2 1 4
*/