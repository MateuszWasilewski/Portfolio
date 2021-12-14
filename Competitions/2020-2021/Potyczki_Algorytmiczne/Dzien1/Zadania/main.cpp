//Wybor Zadan
//Mateusz Wasilewski
#include <bits/stdc++.h>

using namespace std;
int N;
int x, y, c = 1;
int tab[6][3];
bool ans = 1;
string word;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i^N; ++i){
        cin >> word;
        x = word[0]-48;
        y = word[1]-65;
        tab[x][y]++;
    }
    for(int i=1; i<=5; ++i){
        if(i==5) c=2;
        for(int z=0; z^3; ++z){
            if(tab[i][z]<c) ans=0;
        }
    }
    if(ans) cout << "TAK\n";
    else cout << "NIE\n";
    return 0;
}
/*

19
3B 4B 5B 4C 5C 3C 1A 5A 5C 3A 5A 2C 1B 2A 5B 5C 2B 1C 4A

20
2B 4B 4C 5A 5C 5C 4A 1B 3A 4A 2A 3B 1B 1C 1A 5A 2C 1B 5B 3C
*/