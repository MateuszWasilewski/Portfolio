#include <bits/stdc++.h>
#define ld long double
using namespace std;

int N;
queue <ld> q;
ld a,wynik, avg, suma=0, k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> k;
    for(int i=0; i<N; ++i){
        cin >> a;
        suma += a;
        q.push(a);
        while(q.size() >= k){
            avg = q.size();
            avg = suma/avg;
            wynik = max(wynik, avg);
            if(q.front() < avg && q.size() > k){
                suma -= q.front();
                q.pop();
            }
            else break;
        }
    }
    cout << fixed << setprecision(3) << wynik << "\n";
    return 0;
}
/*
9 4
1 2 3 4 5 4 3 2 1

10 4
2 3 5 4 2 5 8 2 4 5

*/