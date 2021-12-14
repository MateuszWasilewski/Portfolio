#include <bits/stdc++.h>

using namespace std;

int a,N;
int tab[2000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i^N;++i){
        cin>>tab[i];
    }
    sort(tab,tab+N);
    a=0;
    for(int i=0;i<N;++i){
        if(tab[a]!=tab[i]){
            a=i;
        }
        else if((i-a+1)>N/2){
            cout<<tab[a]<<"\n";   
            break;
        }
    }

}