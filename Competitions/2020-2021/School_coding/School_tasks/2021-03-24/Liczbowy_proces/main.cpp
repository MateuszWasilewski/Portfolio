#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_set <ll> st;

ll limit = 5e9;
ll a,b,c,d;
int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    a = 1;
    for(int i=0; i<N; ++i){
        cin >> d;

        while(a <= d){
            st.insert(a);
            b = a;
            c = 0;
            while(a){
                c += a%10;
                a /= 10;
            }
            c = c*c;
            a = b + c;
        }

        if(st.find(d) != st.end()) cout << "TAK\n";
        else cout << "NIE\n";
    }
    return 0;
}