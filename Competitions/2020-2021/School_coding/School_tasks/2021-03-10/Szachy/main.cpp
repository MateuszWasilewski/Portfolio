#include <bits/stdc++.h>
#define sz 1010
using namespace std;

int N,M;
int tab[sz][sz];
int maxy[sz][sz][4];
int wynik;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; ++i){
        for(int z=1; z<=M; ++z){
            cin >> tab[i][z];
            maxy[i][z][0] = max(tab[i][z],max(maxy[i-1][z][0],maxy[i][z-1][0]));
        }
        for(int z=M; z>0; --z){
            maxy[i][z][1] = max(tab[i][z],max(maxy[i-1][z][1],maxy[i][z+1][1]));
        }
    }
    for(int i = N; i>0; --i){
        for(int z=1; z<=M; ++z){
            maxy[i][z][2] = max(tab[i][z],max(maxy[i+1][z][2],maxy[i][z-1][2]));
        }
        for(int z=M; z>0; --z){
            maxy[i][z][3] = max(tab[i][z],max(maxy[i+1][z][3],maxy[i][z+1][3]));
        }
    }
    for(int i=1; i<=N; ++i){
        for(int z=1; z<=M; ++z){
            wynik = max(wynik, tab[i][z] + max(
                max(maxy[i-1][z-1][0], maxy[i-1][z+1][1]),
                max(maxy[i+1][z-1][2], maxy[i+1][z+1][3])
            ));
        }
    }

    cout << wynik << "\n";
    return 0;
}

/*
5 6
3 4 2 6 7 6
5 6 4 7 4 3
7 9 4 2 5 2
5 3 8 9 3 2
6 5 7 2 8 1


*/