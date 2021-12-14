//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

int N;
const int limit = 1000007;
int v[limit];
bitset <limit> bt;

bool func(int x){
    if(x == N){
        int p=0;
        int k=0;
        bool fine = 1;
        for(int i=0; i<N && fine; ++i){
            if(bt[i]) p++;
            else k++;
            if(k>p) fine = 0;
        }
        if(p != k) fine = 0;

        p=0;
        k=0;
        for(int i=0; i<N && fine; ++i){
            if(bt[v[i]]) p++;
            else k++;
            if(k>p) fine = 0;
        }
        if(p != k) fine = 0;

        if(fine){
            for(int i=0; i<N; ++i){
                if(bt[i]) cout << "(";
                else cout << ")";
            }
        }
        return fine;
    }
    bool stop = 0;
    bt[x] = 1;
    stop = func(x+1);
    if(!stop){
        bt[x] = 0;
        stop = func(x+1);
    }
    return stop;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> v[i];
        v[i]--;
    }
    if(N%2){
        cout << "NIE\n";
        return 0;
    }
    if(N<20){
        if(!func(0)) cout << "NIE\n";
    }
    else{
        vector <pair<int,int> > kol;
        for(int i=0; i<N; ++i){
            kol.push_back({i+v[i],i});
        }
        sort(kol.begin(), kol.end());
        for(int i=0; i<kol.size(); ++i){
            bool goa  = 1;
            if(i > 0){
                if(kol[i].ff == kol[i-1].ff){
                    bt[kol[i].ss] = !bt[kol[i-1].ss];
                    goa = 0;
                }
            }
            if(goa){
                if( i < N/2) bt[kol[i].ss] = 1;
                else bt[kol[i].ss] = 0;
            }
            
        }
        int p=0;
        int k=0;
        bool fine = 1;
        for(int i=0; i<N && fine; ++i){
            if(bt[i]) p++;
            else k++;
            if(k>p) fine = 0;
        }
        if(p != k) fine = 0;

        p=0;
        k=0;
        for(int i=0; i<N && fine; ++i){
            if(bt[v[i]]) p++;
            else k++;
            if(k>p) fine = 0;
        }
        if(p != k) fine = 0;

        if(fine){
            for(int i=0; i<N; ++i){
                if(bt[i]) cout << "(";
                else cout << ")";
            }
            cout << "\n";
        }
        else cout << "NIE\n";
    }
    

    return 0;
}
/*
10
1 9 8 7 6 5 4 3 2 10
*/