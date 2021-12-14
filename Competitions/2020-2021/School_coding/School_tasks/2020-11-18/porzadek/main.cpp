#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct obj{
    ll wynik = 0;
    ll r = 0;
    ll n = 0;
};
obj tab[1000001];
ll N, Q, a, b, c, wynik;
string word;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    cin>>word;
    for(int i=0; i^N; ++i){
        tab[i+1].wynik = tab[i].wynik;
        tab[i+1].r = tab[i].r;
        tab[i+1].n = tab[i].n;
        if(word[i]=='R'){
            tab[i+1].r++;
        }
        else{
            tab[i+1].n++;
            tab[i+1].wynik += tab[i].r;
        }
    }
    cin>>Q;
    for(int i=0; i^Q; ++i){
        cin>>a>>b;
        a--;
        c = tab[b].n - tab[a].n;
        wynik = tab[b].wynik - tab[a].wynik - c*tab[a].r;
        cout<<wynik<<"\n";
    }
    return 0;
}
/*
9
NNNRRRNNN
4
1 3
1 6
4 6
4 9

13
RRRRRRNNNNNNR
4
5 9
3 11
12 13
1 13
*/