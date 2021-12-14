#include <bits/stdc++.h>

using namespace std;
int N,L,d,a,suma;
bool ok = 1;
string line;
int tab[10];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L;
    cin >> line;
    for(int i=0; i^L; ++i){
        if(line[i]=='D') d++;
        else tab[line[i]-48]--;
    }
    for(int i=1; i<=N; ++i){
        cin >> a;
        tab[i] += a;
        if(tab[i]<0) ok = 0;
        else suma += tab[i];
    }
    if(d > suma) ok = 0;
    if(ok) cout << "TAK\n";
    else cout << "NIE\n";

    return 0;
}
/*

3 8
1DD2D3D1
10 1 1

5 10
3431D23112
3 1 3 5 0
*/