#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int limit = 300010;
ll sumy[limit];
ll wynik[limit];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, k, q, start, kon;
    ll a, suma = 0;
    queue <ll> rm;
    cin >> N >> k >> q;

    for (int i = 1; i <= N; i++) {
        cin >> a;
        suma += a;
        rm.push(a);
        wynik[i] = -1;
        if (rm.size() > k) {
            suma -= rm.front();
            rm.pop();
        }
        if (i >= k)
            sumy[i] = suma;
    }

    vector <pair <pair <int, int>, int> > v;
    vector <pair <int, ll> > odp;
    for (int i = 0; i < q; i++) {
        cin >> start >> kon;
        v.push_back({{start, kon}, i});
    }
    sort(v.begin(), v.end());

    start = 0;
    kon = 0;
    ll score = 0;
    for (int i = 0; i < q; i++) {
        auto e = v[i].first;
        
        if (e.first == start) {
            for (int z = kon + 1; z <= e.second; z++) {
                wynik[z] = 0;
                if (z > start) {
                    wynik[z] = wynik[z - 1];
                    if (z >= start + k - 1) {
                        wynik[z] = max(wynik[z], wynik[z - k] + sumy[z]);
                    }
                }
            }
        }
        else {
            int licz = 0;
            wynik[e.first - 1] = 0;
            for (int z = e.first; z <= e.second; z++) {
                score = 0;
                if (z > e.first) {
                    score = wynik[z - 1];
                    if (z >= e.first + k - 1) {
                        score = max(score, wynik[z - k] + sumy[z]);
                    }
                }
                wynik[z] = score;
            }
            start = e.first;
        }
        kon = e.second;

        odp.push_back({v[i].second, wynik[kon]});
    }
    sort(odp.begin(), odp.end());

    for (int i = 0; i < q; i++) {
        cout << odp[i].second << "\n";
    }
}
/*
20 5 2
-20 7 -15 10 1 18 -15 -4 -18 -12 4 -8 13 -9 -1 -11 -17 -16 11 -6
1 12
1 7

100 5 1
-438 300 -220 150 -222 -324 412 233 -49 -195 21 60 -251 229 101 -99 -456 463 -5 -218 287 -148 280 -393 -350 443 186 118 -162 -109 78 -338 -325 461 -330 -252 -421 -494 140 394 -272 203 107 -424 -20 -288 321 304 37 211 301 55 -8 -87 342 -155 169 -408 60 242 -304 377 -129 184 26 -327 1 337 216 -44 246 -233 397 -313 -184 164 -314 -256 -217 81 209 200 78 295 -479 -495 -147 182 244 128 262 -441 423 -89 412 134 -467 -384 -120 -335
69 95
*/