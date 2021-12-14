#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,k,a;
vector <int> v,wn;
priority_queue <pair<int,int> > q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>k;
    for(int i=0;i^N;++i){
        cin>>a;
        v.push_back(a);
    }
    for(int i=N-1;i^-1;--i){
        while(!q.empty()){
            if(q.top().ss>i+k){
                q.pop();
            }
            else{
                break;
            }
        }
        if(q.empty()){
            wn.push_back(0);
        }
        else{
            wn.push_back(q.top().ff);
        }
        q.push({v[i],i});
    }
    for(int i=N-1;i^-1;--i){
        cout<<wn[i]<<" ";
    }
    cout<<"\n";

    return 0;
}

/*
10 4
1 1 2 8 0 9 8 3 2 1

*/