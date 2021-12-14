#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N,a;
const ll half=1048576;
ll tab[half*2+1];
ll wynik,x,y;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>a;
        x=half+a;
        while(true){
            wynik+=tab[x];
            if(x==1){break;}
            x/=2;
        }
        x=half;
        y=half+a-1;
        while(x!=y && x!=y-1){
            if(x%2==0){
                x/=2;
            }
            else{
                tab[x]++;
                x++;
                x/=2;
            }
            if(y%2==0){
                tab[y]++;
                y--;
                y/=2;
            }
            else{
                y/=2;
            }
        }
        tab[x]++;
        if(x==y-1){tab[y]++;}
    }
    cout<<wynik<<"\n";

    return 0;
}
/*
7
4 2 7 1 5 6 3
*/