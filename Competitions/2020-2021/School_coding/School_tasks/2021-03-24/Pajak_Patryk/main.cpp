#include <bits/stdc++.h>
#define ff first
#define ss second
#define sz 1000010
using namespace std;

int N, d;
int a, b;
int dp[sz];
int lp;
int maxi, odp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> d;

    for(int i=0; i<N; ++i){
        cin >> a >> b;
        dp[a]++;
        dp[b+1]--;
    }

    for(int i=0; i<=d; ++i){
        lp += dp[i];
        if(lp > maxi){
            maxi = lp;
            odp = i;
        }
    }
    cout << odp << "\n";
}

/*
2 4
2 2
1 2


*/