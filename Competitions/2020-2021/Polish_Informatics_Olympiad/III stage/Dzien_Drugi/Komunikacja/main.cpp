//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

const int r = 10;
const int x = 100;
int a,b,N;

ll suma_x, suma_y;
vector <pair<ld,ld> > v;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> a >> b;
        v.push_back({a,b});
    }
    if(true){
        for(auto f:v){
            ld wynik = 0;
            ld a1,a2;
            for(auto e:v){
                a1 = f.ff - e.ff;
                a2 = f.ss - e.ss;
                a1 = a1*a1;
                a2 = a2*a2;
                wynik += sqrt(a1 + a2);
            }
            cout << fixed << setprecision(18) << wynik << "\n";
        }
    }
    


    return 0;
}