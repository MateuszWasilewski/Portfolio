#include <bits/stdc++.h>

using namespace std;

struct obj{
    int wynik;
    vector <int> which;
};
int N, pos;
obj tab[20001];
int limit;
int bank[201][2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0; i<2; ++i){
        for(int z=0; z<N; ++z){
            cin >> bank[z][i];
        }
    }
    cin >> limit;
    for(int i=1; i<=limit; ++i){
        tab[i].wynik = INT32_MAX;
    }
    for(int i=0; i<N; ++i){
        for(int j=limit; j>=0; --j){
            if(tab[j].wynik != INT32_MAX){
                for(int z=1; (z <= bank[i][1]) && (j + z*bank[i][0] <= limit) ; ++z){
                    pos = j+z*bank[i][0];
                    if(tab[j].wynik + z < tab[pos].wynik){
                        tab[pos].wynik = tab[j].wynik + z;
                        tab[pos].which = tab[j].which;
                        tab[pos].which.push_back(z);
                    }
                }
                tab[j].which.push_back(0);
            }
        }
    }
    cout << tab[limit].wynik << "\n";
    for(auto e:tab[limit].which){
        cout << e << " ";
    }
}
/*
3
2 3 5
2 2 1
10


    
*/