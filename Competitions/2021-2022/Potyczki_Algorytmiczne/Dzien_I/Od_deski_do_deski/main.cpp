#include <bits/stdc++.h>

#define ll long long
#define limit 3010
using namespace std;

const ll mod = 1e9 + 7;
ll dp[3][limit];

int main() {
    int n, m, iter, lim;
    cin >> n >> m;

    lim = min(limit, m);
    dp[1][0] = m;
    for (int i = 2; i < n; i++) {
        iter = i % 3;
        for (int z = 0; z < lim; z++) {
            dp[iter][z] = dp[(i - 1) % 3][z] * (ll)(m - z) % mod;
            if (z > 0) {
                dp[iter][z] += dp[(i - 2) % 3][z - 1] * (ll)(m - z) % mod;
                dp[iter][z] %= mod;
            }
        }
    }
    iter = (n - 1) % 3;
    ll wynik = 0;
    for (int i = 0; i < lim; i++) {
        wynik = (wynik + dp[iter][i]) % mod;
    }
    cout << wynik << "\n";
}