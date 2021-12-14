#include <bits/stdc++.h>
#define ll long long
#define sz 1010
using namespace std;

ll N,M,add;
ll dp[sz][sz];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    for(int i=0; i<N; ++i){
        for(int z=0; z<M; ++z){
            cin >> dp[i][z];
        }
    }
    for(int i=N-1; i>=0; --i){
        for(int z=M-1; z>=0; --z){
            if((i+z) % 2 == 0) dp[i][z] += max(dp[i+1][z], dp[i][z+1]);
            else{
                add = INT64_MAX;
                if(i+1 < N) add = min(add, dp[i+1][z]);
                if(z+1 < M) add = min(add, dp[i][z+1]);
                if(add != INT64_MAX) dp[i][z] += add;
            }
        }
    }
    cout << dp[0][0] << "\n";
}
/*
3 3
3 6 3
5 1 4 
4 5 4

2 4
2 6 1 1 3 5 3 4
*/