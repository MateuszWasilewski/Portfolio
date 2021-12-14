#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    
    int N, k, now;
    int pocz = 0;
    long long wynik = 0;
    set <int> st;

    cin >> N >> k;

    for (int i = 0; i < N && st.size() < k; ++i) {
        cin >> now;

        if (st.find(now) == st.end()) {
            st.insert(now);
            wynik += i - pocz;
            pocz++;
        }
    }
    cout << ((int) st.size() == k ? wynik : -1 ) << "\n";
    return 0;
}