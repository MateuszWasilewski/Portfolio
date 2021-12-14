//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

int N,M,a,b;
const int sz = 500010;
pair<int,int> tab[sz];
int odp[sz];
string ans;

int main(int argc, char *argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream input;
    input.open(argv[1], ios::in);
    input >> N >> M;

    cin >> ans;
    if(ans == "TAK"){
        for(int i=1; i<=N; ++i){
            cin >> odp[i];
        }
        for(int i=0; i<M; ++i){
            input >> a >> b;
            if(odp[a] < odp[b]){
                tab[a].ss++;
                tab[b].ff++;
            }
            else{
                tab[a].ff++;
                tab[b].ss++;
            }
        }
        bool ok =  1;
        for(int i=3; i<=N; ++i){
            if(tab[i].ff != tab[i].ss) ok = 0;
        }
        if(ok == 0) cout << "WRONg!!!!\n";
    }
    input.close();

    return 0;
}