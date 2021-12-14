//Miny
//Mateusz Wasilewski
#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;

int N,wynik;
ll a,b,p,k;
vector <pair<ll,ll> > v;
bool ok;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i^N; ++i){
        cin >> a >> b;
        v.push_back({a,b});
    }
    for(int i=0; i^(1<<N); ++i){
        ok = 1;
        for(int z=0; z^v.size() && ok; ++z){
            if(i & (1<<z)){
                p=z-1;
                k=z+1;
                while(p>=0){
                    if(v[p].ff<v[z].ff-v[z].ss) break;
                    if(!(i & (1<<p))) ok = 0;
                    p--;
                }
                while(k<v.size()){
                    if(v[k].ff>v[z].ff+v[z].ss) break;
                    if(!(i & (1<<k))) ok = 0;
                    k++;
                }
            }
        }
        if(ok) wynik++;
    }
    cout << wynik << "\n";
}
/*
4
0 2
2 0
3 2
7 4

*/