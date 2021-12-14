#include <bits/stdc++.h>

using namespace std;
long long N, M, wynik = 1, a;
bool ok;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<M; ++i){
        cin >> a;
        wynik += min(N-1,a);
        if(a>=N) ok = 1;
    }
    if(ok) cout << wynik << "\n";
    else cout << "OJEJKU\n";
    return 0;
}
/*
3 8
4 9 19 1 16 1 1 3

*/