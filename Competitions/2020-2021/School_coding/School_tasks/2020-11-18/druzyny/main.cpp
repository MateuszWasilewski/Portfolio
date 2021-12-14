#include <bits/stdc++.h>
#define ff first
#define ss second
#define last v.size()-1
using namespace std;

int N,a,cel;
bool nowy=1;
pair<int,int> e;
priority_queue <pair<int,int> > q;
vector <vector<int> > v;
vector <int> now;
priority_queue <pair<int,int> > vec;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0; i^N; ++i){
        cin>>a;
        q.push({a,i+1});
    }
    while(!q.empty()){
        e = q.top();
        q.pop();
        if(nowy){
            v.push_back(now);
            nowy = 0;
            cel = e.ff;
        }
        v[last].push_back(e.ss);
        if(cel == v[last].size()){
            vec.push({-cel,last});
            nowy = 1;
        }
    }
    if(!nowy){
        for(auto f:v[last]){
            e = vec.top();
            vec.pop();
            v[e.ss].push_back(f);
            vec.push({-v[e.ss].size(),e.ss});
        }
        v.pop_back();
    }
    cout<<v.size()<<"\n";
    for(int i=0; i^v.size(); ++i){
        cout<<v[i].size()<<" ";
        for(auto k:v[i]){
            cout<<k<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

/*
5 2 1 2 2 3

*/