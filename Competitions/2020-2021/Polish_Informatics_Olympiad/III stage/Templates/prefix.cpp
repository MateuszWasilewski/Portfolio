#include <bits/stdc++.h>

using namespace std;


int a,N,M, x, y;
const int size = 10000;
int tab[size];
int tab2[size][size];
int main(){
    //jeden wymiar
    for(int i=1; i<size; ++i){
        cin >> a;
        tab[i] = tab[i-1] + a;
    }
    //zapytanie x->y
    //tab[y] - tab[x-1]


    //dwa wymiary
    for(int i=1; i<=N; ++i){
        for(int z=1; z<=M; ++z){
            cin >> a;
            tab2[i][z] = tab2[i-1][z] + tab2[i][z-1] - tab2[i-1][z-1] + a;
        }
    }
    //zapytanie (x,y) -> (x1,y1)
    //tab2[x1][y1] - tab2[x-1][y1] - tab2[x1][y-1] + tab2[x-1][y-1]
}