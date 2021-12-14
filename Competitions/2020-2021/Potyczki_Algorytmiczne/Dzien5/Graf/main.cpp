//Graf acykliczny
//Mateusz Wasilewski
#include <bits/stdc++.h>

using namespace std;

int k, n=100;
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin >> k;
    cout << n << "\n";
    for(int i=1; i<=n; ++i){
        if(i<n-1){
            cout << i+1 << " ";
            if(!(i & 1)){
                if(k & 1) cout << n << "\n";
                else cout << "-1\n";
                k >>= 1;
            }
            else if(i<n-2) cout << i+2 << "\n";
            else cout << "-1\n";
        }
        else{
            cout << "-1 -1\n";
        }
    }
    return 0;
}