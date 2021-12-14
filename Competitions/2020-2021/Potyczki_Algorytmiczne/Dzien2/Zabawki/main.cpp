//Zabawki
//Mateusz Wasilewski
#include <bits/stdc++.h>
using namespace std;

int N;
int tab[2][2][26];
bool ok = 1;
string line;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i^2; ++i){
        cin >> line;
        for(int z=0; z^N; ++z){
            tab[i][z%2][line[z]-97]++;
        }
    }
    for(int z=0; z^26 && ok; ++z){
        for(int i=0; i^2 && ok; ++i){
            ok = ! (tab[0][i][z] ^ tab[1][i][z]);
        }
    }
    if(ok) cout << "TAK\n";
    else cout << "NIE\n";

    return 0;
}
/*7
abcdefg
edgbcfa
5
abcde
fghhh
*/