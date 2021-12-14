#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
ll a,suma,wynik;
vector <ll> v;
class obj{
public:
    int p;
    ll suma;
};

obj ob1;
obj ob2;
obj ob3;
obj ob4;
ll maxi(){
    return max(max(ob1.suma,ob2.suma),max(ob3.suma,ob4.suma));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i^N;++i){
        cin>>a;
        suma+=a;
        v.push_back(a);
    }
    ob1.p=0,ob1.suma=v[0];
    ob2.p=1,ob2.suma=v[1];
    ob3.p=2,ob3.suma=v[2];
    ob4.p=3,ob4.suma=suma-v[0]-v[1]-v[2];
    while(true){
        a=maxi();
        wynik=max(wynik,a);
        if(ob1.suma==a){
            break;
        }
        else if(ob2.suma==a){
            
        }
        else if(ob3.suma==a){

        }
        else{

        }
    }

}