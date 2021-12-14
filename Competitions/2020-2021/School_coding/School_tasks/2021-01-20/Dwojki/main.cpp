#include <bits/stdc++.h>

using namespace std;
int N,a;
set <int> st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> a;
        bool poz = st.insert(a).second;
        if(!poz) st.erase(a);
    }
    auto poz = st.begin();
    cout << *poz << "\n";
    return 0;
}