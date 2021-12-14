#include <bits/stdc++.h>

using namespace std;
int N,half,W,X;
int wynik = INT32_MAX;
string word;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> word;
    half = (N+1)/2;
    for(int i=0; i<N; ++i){
        if(word[i]=='X') X++;
        else W++;
        if(i>=half){
            if(word[i-half]=='X') X--;
            wynik = min(wynik, X);
        }
    }
    wynik = min(wynik, X);
    cout << wynik + W << "\n";
}

/*
10
WXXWXWWXWX
*/