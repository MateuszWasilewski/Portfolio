#include <bits/stdc++.h>

using namespace std;

int N;
double x,y,a,b;
set <pair<double,double> > st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i^N; ++i){
        cin>>x>>y;
        if(x==0){
            a=1e10;
            b=y/abs(y);
        }
        else{
            a=y/x;
            b=x/abs(x);
        }
        //cout<<a<<" "<<b<<"\n";
        auto poz=st.find({a,b});
        if(poz==st.end()){
            st.insert({a,b});
        }
    }
    cout<<st.size()<<"\n";

    return 0;
}
/*
5
2 2
3 3
1 -2
-3 5
2 -4

*/