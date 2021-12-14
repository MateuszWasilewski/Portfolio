#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
using namespace std;

int N;
ll a,b,c,wynik,x,y;
ll t1,t2;
vector <pair<ll,ll> > v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0; i^N; ++i){
        cin>>c>>a>>b;
        if(c==1){
            v.push_back({a*a+2*a*b,b*b});
        }
        else{
            wynik = 0;
            t1 = a*a;
            t2 = b*b + 2*a*b;
            for(auto e:v){
                a = min(e.ff*t1,e.ss*t2);
                wynik = max(wynik, a);
            }
            cout<<wynik<<"\n";
        }
    }


}
/*
10
2 4741 8259
1 6098 5517
2 1061 2379
1 529 5008
2 1951 3683
2 1350 2786
2 3973 9494
1 7318 2675
1 2970 3993
2 3686 9781

5
1 5 4
2 1 1
1 3 6
1 1 9
2 2 1

*/