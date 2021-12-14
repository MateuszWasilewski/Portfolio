//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

int N;
ll tab[200][200];
char test;
string line;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    tab[1][1] = 1;
    for(int i=1;i <= N; ++i){
        cin >> line;
        for(int z=1; z<= N; ++z){
            if(line[z-1] == '.' && i*z != 1){
                tab[i][z] = tab[i][z-1] + tab[i-1][z];
            }
        }
    }
    cout << tab[N][N] << "\n";


    return 0;
}
/*
4
...#
....
##..
###.

*/