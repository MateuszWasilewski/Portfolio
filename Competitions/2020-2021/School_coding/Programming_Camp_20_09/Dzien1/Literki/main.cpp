#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N,wynik;
vector <ll> v[30][2];
string line[2];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cin>>line[0];
    cin>>line[1];
    for(int i=0;i<N;++i){
        for(int z=0;z<2;++z){
            v[line[z][i]-'A'][z].push_back(i);
        }
    }
    for(int i=0;i<30;++i){
        for(int z=0;z<v[i][0].size();++z){
            wynik+=abs(v[i][0][z]-v[i][1][z]);
        }
    }
    cout<<wynik/2<<"\n";

}