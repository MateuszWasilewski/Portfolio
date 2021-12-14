#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string ans = "", line;
    int n;
    int zera = 0, jeden = 0;

    cin >> n;
    n *= 8;
    cin >> line;
    for (int i = 0; i < n; i++) {
        jeden += (line[i] == '1');
    }

    n /= 8;

    if (jeden < n * 3 || jeden > n * 6) {
        cout << "NIE\n";
    }
    else{
        char znak;
        int mod;
        while (n) {
            n--;
            znak = 0;
            znak ^= 97;
            jeden -= 3;

            mod = 2;
            while (jeden > n * 6) {
                znak ^= mod;
                jeden --;
                mod <<= 1;
            }

            cout << znak;
        }
        cout << "\n";
    }


    return 0;
}