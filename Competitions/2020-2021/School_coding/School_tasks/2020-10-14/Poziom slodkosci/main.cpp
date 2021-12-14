#include <bits/stdc++.h>
#define ll long long
using namespace std;
int N;
ll x,k;
ll wynik=LONG_LONG_MAX;
ll dp[500001];
multiset <ll> st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>k;
    st.insert(0);
    for(int i=1;i<=N;++i){
        cin>>x;
        dp[i]=dp[i-1]+x;
        st.insert(dp[i]);
    }
    for(int i=0;i<=N;++i){
        x=dp[i];
        st.erase(x);
        x=x+k;
        auto poz=st.lower_bound(x);
        if(poz!=st.end())
            wynik=min(wynik,abs(*poz - x));
        if(poz!=st.begin()){
            poz--;
            wynik=min(wynik,abs(*poz - x));
        }
    }
    cout<<wynik<<"\n";

}

/*
5 12
4 3 -9 16 9

8 30
4 12 12 10 -5 15 6 -5

6 10
1 4 20 -21 8 4
*/