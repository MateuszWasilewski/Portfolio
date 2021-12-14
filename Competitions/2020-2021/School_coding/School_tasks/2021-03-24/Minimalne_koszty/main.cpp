#include <bits/stdc++.h>
#define sz 1<<16
#define ff first
#define ss second
using namespace std;

int dp[sz];
int now[sz];
int N, M;
int cost, a, b;

void go_front(int x, int limit, int k){
    if(k >= limit) return;

    go_front(x, limit, k*2);
    if(!(limit & k)){
        x += k;
        dp[limit + x] = min(dp[limit + x], dp[limit] + dp[x]);
        go_front(x, limit, k*2);
    }
    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int size = 1<<M;
    for(int i=1; i<size; ++i){
        dp[i] = INT32_MAX;
    }

    for(int i=0; i<N; ++i){
        cin >> cost;
        now[0] = cost;
        for(int z=1; z<size; ++z){
            now[z] = INT32_MAX;
        }

        b = 1;
        for(int z=0; z<M; ++z){
            cin >> a;
            for(int k = 0; k<b; ++k){
                now[b+k] = now[k] + a;
            }
            b *= 2;
        }

        for(int z=1; z< size; ++z){
            dp[z] = min(dp[z], now[z]);
        }
    }

    for(int i=1; i < size; ++i){
        go_front(0,i,1);
    }

    cout << dp[size-1] << "\n";
}
/*
3 4
5 7 3 7 9
2 1 20 3 2
8 1 20 1 1
*/