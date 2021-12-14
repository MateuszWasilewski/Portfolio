#include <bits/stdc++.h>

using namespace std;

int N, w, d, a, suma, deska;
int p;
int wynik;
int tab[10];//2000001];
deque <int> dq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> w >> d;
    p = 1-d;
    for(int i=1; i<=N; ++i){
        cin >> a;
        tab[i] = tab[i-1] + a;
        deska = tab[i]-tab[max(0,max(i-d,p))];

        while(!dq.empty()){
            if(dq.back() < deska) dq.pop_back();
            else break;
        }
        dq.push_back(deska);
        
        while(!dq.empty()){
            if(tab[i]-tab[max(0,p-1)] > dq.front()+w){
                deska = tab[min(i,p+d-1)] - tab[p-1];
                if(dq.front() == deska){
                    dq.pop_front();
                }
                p++;
            }
            else{
                wynik = max(wynik, i- max(1,p) +1);
                break;
            }
        }
    }
    cout << wynik << "\n";
    return 0;
}
/*
9 7 2
3 4 1 9 4 1 7 1 3

*/