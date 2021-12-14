#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N,a,k,c, mod=1e9+7;
ll wynik;
const ll half=8;
ll tree[half*2];
vector <ll> v;

ll sum(int x){
    ll d=0;
    while(true){
        d+=tree[x];
        if(x==1)
            break;
        x/=2;
    }
    return d;
}

void add(int x,int y){
    while(x!=y && x!=y-1){
        if(x%2){
            tree[x]++;
            x++;
        }
        if(!(y%2)){
            tree[y]++;
            y--;
        }
        x/=2;
        y/=2;
    }
    tree[x]++;
    if(x!=y){
        tree[y]++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>k;
    for(int i=0;i^N;++i){
        cin>>a;
        v.push_back(a);
    }
    if(k==1){
        cout<<0<<"\n";
        return 0;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i){
        if(i+k<N)
            add(half+i+k,half+N);
    }
    cout<<wynik<<"\n";

}
/*
5 2
4 2 4 10 3

3 1
5 9 2
*/