#include <bits/stdc++.h>

using namespace std;


struct tab {
    int tb[3];
};

bool cmp(const tab &a, const tab &b) {
    for(int i = 0; i<3; i++) {
        if(a.tb[i] < b.tb[i])
            return true;
    }
    return false;
}

bool Comp(pair<int, tab> a, pair<int, tab> b) {
    return (a.first > b.first);
}

set <tab, decltype(cmp)*> st(cmp);
queue < pair<int, tab>> q;
const int limit = 10;
int wyniki[limit];
tab lim;

tab func(tab now, int s, int k) {
    int place = lim.tb[k] - now.tb[k];
    int move = min(place, now.tb[s]);
    now.tb[k] += move;
    now.tb[s] -= move;

    return now;
}

void Try(tab now, const int &score) {
    const int prev = st.size();
    st.insert(now).second;
    const int curr = st.size();
    if (prev < curr) {
        q.push({score, now});
        for (int i = 0; i < 3; i++) {
            wyniki[now.tb[i]] = min(wyniki[now.tb[i]], score);
        }
    }
}


int main() {
    tab woda;
    int score;

    for(int i = 0; i < 3; i++)
        cin >> lim.tb[i];
    for(int i = 0; i < 3; i++)
        cin >> woda.tb[i];

    for (int i = 0; i < limit; i++) {
        wyniki[i] = INT32_MAX;
    }

    q.push({0,woda});
    st.insert(woda);
    for (int i = 0; i < 3; i++) {
        wyniki[woda.tb[i]] = 0;
    }

    while (!q.empty()) {
        cout << q.size() << "\n";
        auto e = q.front();
        q.pop();
        score = e.first + 1;

        Try(func(e.second, 0, 1), score);
        Try(func(e.second, 1, 0), score);
        Try(func(e.second, 0, 2), score);
        Try(func(e.second, 2, 0), score);
        Try(func(e.second, 1, 2), score);
        Try(func(e.second, 2, 1), score);

    }
    for (int i = 0; i <= lim.tb[2]; i++) {
        cout << (wyniki[i] == INT32_MAX ? -1 : wyniki[i]) << " "; 
    }
    cout << "\n";
}
/*
2 7 9
1 3 6

20 50 100
13 34 66
*/