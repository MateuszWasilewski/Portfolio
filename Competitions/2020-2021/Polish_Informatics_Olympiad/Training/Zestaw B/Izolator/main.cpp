#include <bits/stdc++.h>

using namespace std;

int N, wynik, p, k, a;
vector <int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> a;
        wynik += a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    p=0;
    k=v.size()-1;

    while(p < k){
        wynik += v[k]-v[p];
        p++;
        k--;
    }
    cout << wynik << "\n";
    return 0;
}

/*
4
5
4
1
7
*/