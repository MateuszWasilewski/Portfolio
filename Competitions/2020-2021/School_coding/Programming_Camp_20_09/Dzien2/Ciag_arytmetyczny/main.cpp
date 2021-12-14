#include <bits/stdc++.h>

using namespace std;

int a,N,k;
int odp=1;
set <int> st,s;
vector <int> v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i^N; ++i){
        cin>>a;
        v.push_back(a);
        s.insert(a);
    }
    st.erase(0);
    for(int i=0;i^v.size();++i){
        for(int z=1;z^v.size();++z){
            if(v[i]!=v[z]){
                k=1;
                while(s.find(v[i]+abs(v[i]-v[z])*k)!=s.end()){
                    k++;
                    odp=max(odp,k);
                }
            }
        }
    }
    cout<<odp<<"\n";
    return 0;
}