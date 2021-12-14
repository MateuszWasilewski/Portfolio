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
int half;
int a;
const int limit=1000007;
int v[limit];
bitset <limit> bt;
bool swp;

bool check(){
    bool fine = 1;
    int p=0,k=0;
    for(int i=1; i<=N && fine; ++i){
        if(bt[i]) p++;
        else k++;
        if(k>p) fine = 0;
    }
    if(p != k) fine = 0;

    p=0;
    k=0;
    for(int i=1; i<=N && fine; ++i){
        if(bt[v[i]]) p++;
        else k++;
        if(k>p) fine = 0;
    }
    if(p != k) fine = 0;
    
    return fine;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i=1; i<=N; ++i){
        cin >> a;
        v[i] = a;
        if(i%2==1){
            bt[i] = 1;
        }
        else bt[i] = 0;
    }

    if(N%2){
        cout << "NIE\n";
        return 0;
    }

    half= N/2;
    int p =1;
    int k = N;
    while(p < k && !check()){
        while(bt[v[p]]) p++;

        while(!bt[v[k]]) k--;

        bt[v[p]] = 1;
        bt[v[k]] = 0;
        if(!check()){
            bt[v[p]] = 0;
            bt[v[k]] = 1;
        }
        p++;
        k--;
    }
    if(check()){
        for(int i=1; i<=N; ++i){
            if(bt[i]) cout << '(';
            else cout << ")";
        }
        cout << "\n";
    }
    else{
        cout <<"NIE\n";
    }


    return 0;
}
/*
6
4 6 1 2 3 5
*/