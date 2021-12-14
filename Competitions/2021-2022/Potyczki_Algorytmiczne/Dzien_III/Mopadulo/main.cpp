#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9 +7;
const int limit = 10;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int N;
    ll a, now;
    cin >> N;
    ll tab[limit][2];
    tab[0][0] = 1;
    tab[0][1] = 0;

    for (int i = 1; i <= N; i++) {
        tab[i][0] = 0;
        tab[i][1] = 0;
        cin >> a;

        tab[i][1] = tab[i - 1][1] + a;
        tab[i][1] %= mod;
        for (int z = 0; z < i; z++) {
            now = tab[i][1] - tab[z][1] + mod;
            now %= mod;
            if (now % 2 == 0) {
                tab[i][0] += tab[z][0];
                tab[i][0] %= mod;
            }
        }
    }
    cout << tab[N][0] << "\n";
}