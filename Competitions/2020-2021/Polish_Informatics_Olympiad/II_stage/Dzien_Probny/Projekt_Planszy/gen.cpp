//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;


int main(int argc, char* argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll arg = *reinterpret_cast< ll*>(argv[1]);
    srand(time(NULL) * arg);
    ll x = rand();
    ll y = rand();
    cout << x*y << "\n";

    return 0;
}