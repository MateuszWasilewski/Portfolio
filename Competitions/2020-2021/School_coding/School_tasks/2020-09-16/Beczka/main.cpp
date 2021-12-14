#include <bits/stdc++.h>
#define ss second
#define ff first
#define ld long double
using namespace std;
ld S,H,V,N;
ld L,D;
ld h;
ld jd=1;
ld a,b,c;
vector <pair<ld,ld> > vec;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>S>>H>>V;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>L>>D;
        vec.push_back({L,min(D,jd)});
    }
    a=V/S;
    c=H;
    for(int i=0;i<600;++i){
        h=(a+c)/2;
        b=V;
        for(int z=0;z<vec.size();++z){
            b+=vec[z].ff*vec[z].ff*max(min(h,vec[z].ff*vec[z].ss),vec[z].ff-(H-h));
        }
        if(b==h*S){
            break;
        }
        else if(b>h*S){
            a=h;
        }
        else{
            c=h;
        }
    }
    cout<<fixed<<setprecision(4)<<h<<"\n";

    return 0;
}

/*
100 10 500
1
1 0.5

*/