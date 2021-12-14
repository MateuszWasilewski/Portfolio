#include <bits/stdc++.h>

using namespace std;
unordered_set <int> st;
int N,a,maxi;
bool ok;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i^N; ++i){
        cin>>a;
        st.insert(a);
    }
    maxi=1000;
    auto xd=st.end();
    for(auto poz=st.begin(); poz!=st.end(); ++poz){
        a=*poz;
        if(a<=1000){
            if(st.find(a*a*a)!=xd){
                if(st.find(a*a)!=xd){
                    cout<<a<<"\n";
                return 0;
                }
            }
        }
    }
    cout<<"NIE\n";
}
/*
5
2 5 4 8 3
*/