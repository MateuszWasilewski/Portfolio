#include <bits/stdc++.h>
#define sz 210
#define ff first
#define ss second
using namespace std;

int N,M;
int tab[sz][sz];
int licz[2];
int wynik;


void atak(int x, int y, int way);
void dfs(int x, int y, int way);


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int x,y;
    cin >> N >> M;
    for(int i=0; i<M; ++i){
        cin >> x >> y;
        tab[x][y] = -1;
    }

    for(int i=1; i<=N; ++i){
        for(int z=1; z<=N; ++z){
            if(tab[i][z] == 0){
                dfs(i,z,1);
                wynik += max(licz[0], licz[1]);
                licz[0] = 0;
                licz[1] = 0;
            }
        }
    }

    cout << wynik << "\n";
}

void atak(int x, int y, int way){
    if(x > 0 && y > 0 && x <= N && y <=N){
        if(tab[x][y] == 0){
            dfs(x, y, way);
        }
    }
    return;
}

void dfs(int x, int y, int way = 1){
    tab[x][y] = 1;
    licz[way]++;

    way ^= 1;
    atak(x+2,y+1,way);
    atak(x+1,y+2,way);
    atak(x-2,y+1,way);
    atak(x-1,y+2,way);
    atak(x+2,y-1,way);
    atak(x+1,y-2,way);
    atak(x-2,y-1,way);
    atak(x-1,y-2,way);

    return;
}