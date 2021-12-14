#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;

ll N;
int k=0;
ll srt,maxi;
pair<ll,int> wynik;
vector <ll> prime;
vector <pair<ll,pair<int,int> > > odp[10000];

void samoyed(ll x){
    bool ok = 1;
    for(int i=0; i<prime.size() && ok; ++i){
        if(x%prime[i]==0) ok=0;
    }
    if (ok) prime.push_back(x);
    return;
}
void calculate(int x){
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    srt = sqrt(N);
    for(int i=2; i<=srt; ++i){
        samoyed(i);
    }
    samoyed(N);
    ll p,k,ml,x;
    for(int i=1; i<=N; ++i){
        p = LLONG_MAX;
        k = LLONG_MAX;
        ml=1;
        x =i;
        for(auto e:prime){
            p = k;
            k = 0;
            while(x%e==0){
                x/=e;
                k++;
            }
            if(k>p) break;
            ml*=(k+1);
        }
        if(ml > maxi){
            maxi = ml;
            cout<< "v.push_back(" << i << ");\n";
        }
    }


}