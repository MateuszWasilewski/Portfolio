//Elektrownie i Fabryki
//Mateusz Wasilewski
#include <bits/stdc++.h>
using namespace std;

struct str{
public:
    int ok = 0;
    int wynik = 0;
};
const int SIZE_OF = 5007;
int N, a;
int tab[SIZE_OF];

str wyniki[SIZE_OF][SIZE_OF];

str func(int p, int k);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> a;
        tab[i] = tab[i-1]+a;
        if(a >= 0) wyniki[i][i].ok = 1;
        else wyniki[i][i].ok = -1;
    }

    str ans = func(1,N);
    if(ans.ok == -1) cout << "-1\n";
    else cout << N -1 - ans.wynik << "\n";

    return 0;
}

str func(int p, int k){
    if(wyniki[p][k].ok == 0){
        int suma;
        suma = tab[k] - tab[p-1];

        if(suma>=0){
            wyniki[p][k].ok = 1;

            str ob1, ob2;
            for(int i=p; i^k; ++i){
                ob1 = func(p, i);
                ob2 = func(i+1, k);

                if(ob1.ok == 1 && ob2.ok == 1){
                    wyniki[p][k].wynik = max(wyniki[p][k].wynik, ob1.wynik + ob2.wynik + 1);
                }
            }
        }
        else wyniki[p][k].ok = -1;
    }
    return wyniki[p][k];
}
/*
17
2 -5 0 2 0 0 0 4 0 0 -1 4 0 0 0 0 -3

*/