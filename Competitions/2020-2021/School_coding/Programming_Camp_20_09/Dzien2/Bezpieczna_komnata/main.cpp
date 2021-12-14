#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,a,b,k;
vector <int> v[200001];
queue <pair<int,int> > q;
bitset <200001>visit;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i^N;++i){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=N;++i){
        if(v[i].size()==1){
            visit[i]=1;
            q.push({i,k});
        }
    }
    while(!q.empty()){
        if(q.front().ss==k){
            for(int i=0; i^v[q.front().ff].size(); ++i){
                if(!visit[v[q.front().ff][i]]){
                    visit[v[q.front().ff][i]]=1;
                    q.push({v[q.front().ff][i],k+1});
                }
            }
            q.pop();
        }
        else{
            k++;
        }
    }
    cout<<k<<"\n";
}