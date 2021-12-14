#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
vector <ll> v(1,1);
ll pod;
ll mod = 1e9 + 9;


int main(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        v.push_back(0);
        v[i] = v[i-1]*2 % mod;
        if(i>1){
            v[i] = (v[i] + v[i-2] * 5 % mod) % mod;
        }
        if(i>2){
            pod = (pod + v[i-3]) % mod;
            v[i] = (v[i] + pod * 4 % mod) % mod;
        }
    }
    cout << v[N] << "\n";
    return 0;
}