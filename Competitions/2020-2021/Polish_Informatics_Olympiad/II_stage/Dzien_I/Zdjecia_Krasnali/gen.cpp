//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

vector <pair<int,int> > ot;
int N = 10,M,seed =2;

void DFS(int x, int y){
    int a = x,b = y;
    while(x != y){
        while(a == x) a = rand() % N + 1;
        while(b == y) b = rand() % N + 1;
        ot.push_back({x,a});
        ot.push_back({y,b});
        x = a;
        y = b;
    }
}

int main(int argc, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    N = strtol(argv[1], NULL, 10);
    seed = strtol(argv[2], NULL, 10);
    srand(time(NULL) * seed);
    
    int a = rand() % (N-2) + 2;
    ot.push_back({1,a});
    DFS(1,a);

    cout << N << " " << ot.size() << "\n";
    for(auto e:ot){
        cout << e.ff << " " << e.ss << "\n";
    }

    return 0;
}