#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N, a;
    vector <ll> v;
    vector <ll> org;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
        org.push_back(a);
    }
    sort(v.begin(), v.end());
    
    int p = 0, k = N - 1, mid;
    ll ans = LLONG_MAX;
    while (p <= k) {
        mid = (p + k)/2;
        ll masa = v[mid];
        a = masa;
        v[mid] = 0;

        int iter = 0;
        while (iter < N && masa > v[iter]) {
            masa += v[iter];
            iter++;
        }

        v[mid] = a;

        if(iter == N) {
            ans = v[mid];
            k = mid - 1;
        }
        else
            p = mid + 1;
    }

    for(int i = 0; i < N; i++) {
        cout << (org[i] >= ans ? 'T' : 'N');
    }
    cout << "\n";
}