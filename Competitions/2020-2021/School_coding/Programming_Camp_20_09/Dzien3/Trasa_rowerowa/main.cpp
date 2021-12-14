#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int N,M;
int a,b,c,d;
vector <pair<int,int> > v[1001];
priority_queue <pair<int,pair<int,int> >, vector<pair<int,pair<int,int> >>, greater<pair<int,pair<int,int> >> > q;
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pol[1001];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(int i=0; i^M;++i){
        cin>>a>>b>>c>>d;
        v[a].push_back({c,b});
        v[b].push_back({d,a});
    }
    for(auto e:v[1]){
        q.push({e.ff,{e.ss,0}});
    }
    /*while(!q.empty()){
        cout<<q.top().ff<<" "<<q.top().ss<<"\n";
        q.pop();
    }*/
    while(!q.empty() && pol[1].empty()){
        auto e=q.top();
        q.pop();
        for(auto f:v[e.ss.ff]){
            if(e.ss.ss!=f.ss){
                e.ff=max(e.ff,f.ff);
                e.ss.ss=e.ss.ff;
                e.ss.ff=f.ss;
                pol[e.ss.ff].push({e.ff,e.ss.ss});
                q.push(e);
            }
        }
    }
    if(pol[1].empty()){
        
    }

}

/*
4 4
1 2 2 4
2 3 3 4
3 4 4 4
4 1 5 4

*/