#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue < pair < int, int > > q;
    int n, t;
    string line;

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> t;
        cin >> line;

        while (!q.empty())
            q.pop();
        int licz = 0, ile;
        int wynik = 0;
        for (int z = 0; z < t; z++) {
            if (line[z] == '0') {
                licz++;
            }
            else {
                if(licz) {
                    ile = 0;
                    ile += (licz != z);
                    ile += (z < t);

                    q.push({-ile, licz});
                    licz = 0;
                }
                wynik++;
            }
        }
        if (licz > 0)
            q.push({-1, licz});

        ile = 0;
        while (!q.empty()) {
            auto a = q.top();
            swap(a.first, a.second);
            a.second *= -1;
            q.pop();
            if (a.first <= ile * a.second)
                wynik += a.first;
            else {
                wynik += ile * a.second;
                a.first = min(a.first - ile * a.second , a.second);
                if (a.first == 2)
                    wynik ++;
                ile += a.first;
            }
        }
        cout << wynik << "\n";
    }
}