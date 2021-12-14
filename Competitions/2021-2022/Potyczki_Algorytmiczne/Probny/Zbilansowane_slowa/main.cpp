#include <bits/stdc++.h>

#define LIMIT 10000

using namespace std;

int licz[LIMIT][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string line;
    cin >> line;

    int wynik = 0;
    int a, b, c;

    for (int i = 0; i < line.size(); ) {
        licz[i+1][0] = licz[i][0];
        licz[i+1][1] = licz[i][1];
        licz[i+1][2] = licz[i][2];

        licz[i+1][line[i] - 'a']++;

        i++;
        for (int p = 0; p < i; p++) {
            a = licz[i][0] - licz[p][0];
            b = licz[i][1] - licz[p][1];
            c = licz[i][2] - licz[p][2];

            if (a > b) swap(a,b);
            if (b > c) swap(b,c);
            if (a > b) swap(a,b);

            if(a == 0) {
                if(b==0)
                    wynik++;
                else {
                    if(b == c)
                        wynik++;
                }
            }
            else if(a==b && a==c)
                wynik++;
        }
    }

    cout << wynik << "\n";

    return 0;

}