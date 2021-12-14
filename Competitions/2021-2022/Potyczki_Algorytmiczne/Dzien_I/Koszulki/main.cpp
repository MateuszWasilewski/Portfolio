#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    int a, wynik = 0;
    priority_queue <int> q;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        q.push(a);
    }

    a = 0;
    while (!q.empty()) {
        if (k > 0 || q.top() == a) {
            wynik ++;
            k--;
            a = q.top();
            q.pop();
        }
        else 
            break;
    }
    cout << wynik << "\n";
}