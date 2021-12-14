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

set <pair<int,pair<int,int>>> st;
queue < pair<int, pair<int,pair<int,int>>>> q;
const int limit = 100010;
int wyniki[limit];
tab lim;

int * Id(pair<int,pair<int,int>> &now, int x){
    if (x == 0)
        return &(now.first);
    if (x == 1)
        return &(now.second.first);
    else
        return &(now.second.second);
}

pair<int,pair<int,int>> func(pair<int,pair<int,int>> now, int s, int k) {
    int place = lim.tb[k] - *Id(now, k);
    int move = min(place, *Id(now, s));
    *Id(now, k) += move;
    *Id(now, s) -= move;

    return now;
}

void Try(pair<int,pair<int,int>> now, const int &score) {
    const int prev = st.size();
    st.insert(now).second;
    const int curr = st.size();
    if (prev < curr) {
        q.push({score, now});
        for (int i = 0; i < 3; i++) {
            wyniki[*Id(now, i)] = min(wyniki[*Id(now, i)], score);
        }
    }
}


int main() {
    pair<int,pair<int,int>> woda;
    int score;

    for(int i = 0; i < 3; i++)
        cin >> lim.tb[i];
    
    cin >> woda.first >> woda.second.first >> woda.second.second;

    for (int i = 0; i < limit; i++) {
        wyniki[i] = INT32_MAX;
    }

    q.push({0,woda});
    st.insert(woda);
    for (int i = 0; i < 3; i++) {
        wyniki[*Id(woda, i)] = 0;
    }

    while (!q.empty()) {
        //cout << q.size() << "\n";
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