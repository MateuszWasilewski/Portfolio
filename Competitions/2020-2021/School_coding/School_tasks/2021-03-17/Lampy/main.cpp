#include <bits/stdc++.h>
#define ff first
#define ss second
#define ld long double
using namespace std;

int N, k , D;
int licz;
ld a,b,c, d;
ld wynik = 0;
priority_queue <pair<ld,pair<ld,ld > > > q;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> k >> D;
    cin >> a;
    c = D;
    for(int i=1; i<N; ++i){
        cin >> b;

        c = b-a;
        c = c*c/2;
        d = c/2;
        q.push({c-d,{b-a,1}});
        a = b;
    }
    while(k>0){
        auto e = q.top();
        q.pop();
        k--;
        e.ss.ss++;
        c = e.ss.ff*e.ss.ff/e.ss.ss/2;
        d = e.ss.ff*e.ss.ff/(e.ss.ss+1)/2;

        q.push({c-d,{e.ss.ff,e.ss.ss}});
    }
    while(!q.empty()){
        auto e = q.top();
        q.pop();
        c = e.ss.ff*e.ss.ff/e.ss.ss/2;
        wynik += c;
    }
    wynik/=2;
    cout << fixed << setprecision(12) << wynik << "\n";
}

/*
3 1 5
0 3 5

4 3 18
0 1 13 18

2 1000 1000
0 1000
*/