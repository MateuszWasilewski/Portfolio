#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a,b;
ll wyn;
int main(){
    cin>>a>>b;
    for(ll i=0; i<a; ++i){
        for(ll z=0; z<b; ++z){
            wyn+= (i+1)*(z+1)*(a-i)*(b-z);
        }
    }
    cout<<wyn<<"\n";
    return 0;
}