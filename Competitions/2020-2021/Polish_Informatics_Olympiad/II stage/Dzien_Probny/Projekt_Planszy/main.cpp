//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

char tab[200][200];
ll K;
bool way = 1;
int x,y;
int N = 100;

void read(){
    for(int i=1; i<=N; ++i){
        for(int z=1; z<=N; ++z){
            cout << tab[i][z];
        }
        cout << "\n";
    }
}
void use(int x, int y){
    tab[x][y] = '.';
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> K;
    //początkowe przygotowanie
    for(int i=1; i<=N; ++i){
        for(int z=1; z<=N; ++z){
            tab[i][z] = '#';
        }
    }
    for(int i=1; i<=N; ++i){
        use(i,N);
        use(N,i);
    }


    //algos
    x = 1; y =1;
    while(K){
        use(x,y);
        use(x+1,y);
        use(x,y+1);
        use(x+1,y+1);
        if(K%2){
            if(way) for(int i=x+2; i<N; ++i) use(i,y);
            else for(int i=y+2; i<N; ++i) use(x,i);
        }
        x++;
        y++;
        if(way) y++;
        else x++;
        way = !way;
        K >>= 1;
    }
    cout << N << "\n";
    read();
    return 0;
}

/*
576460752303423488

576460752303423487

1000000000000000000

*/