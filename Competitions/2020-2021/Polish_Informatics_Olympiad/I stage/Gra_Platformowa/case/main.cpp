#include <bits/stdc++.h>

using namespace std;
int x=1000000;
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cout<<"2 1000000000 2\n";
    cout<<x<<" ";
    for(int i=1; i<=x; ++i){
        cout<<i*2<<" ";
    }
    cout<<"\n"<<x<<" ";
    for(int i=1; i<=x; ++i){
        cout<<i*2+1<<" ";
    }
    cout<<"\n"<<1<<"\n"<<2<<"\n";
}