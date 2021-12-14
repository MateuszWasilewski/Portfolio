#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
using namespace std;

int N,s,l,r,x;
pair <int,int> mini;
ll wynik;
bool way;
deque <int> dq;
vector <int> ans;
vector <pair<int,int> > cost;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> s;
    for(int i=1; i<=N; ++i){
        dq.push_back(i);
    }
    for(int i=1; i<N; ++i){
        cin >> l >> r;
        //cost.push_back({l,r});
        wynik += min(l,r);

        if( (l<=r) == way){
            if(abs(l-r) < mini.ff){
                mini = {abs(l-r), i};
            }
        }
        else{
            
        }
    }
}