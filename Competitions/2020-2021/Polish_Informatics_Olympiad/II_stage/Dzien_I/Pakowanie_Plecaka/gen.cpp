//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

int N=10,limit=100, seed=1;

int main(int argc, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    N = strtol(argv[1], NULL, 10);
    seed = strtol(argv[2], NULL, 10);
    limit = strtol(argv[3], NULL, 10);
    //N = *reinterpret_cast<int*>(argv[1]);
    //seed = *reinterpret_cast<int*>(argv[2]);
    //limit = *reinterpret_cast<int*>(argv[3]);
    srand(time(NULL) * seed);

    cout << N << "\n";
    for(int i=0; i<N; ++i){
        if(i%10) cout << rand() % limit/10 + 1 << " ";
        else cout << rand() % limit + 1 << " ";
    }
    cout << "\n";

    return 0;
}