#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

vector <int> v[200001];
int N,a,b;
pair<int,int> c;
pair<int,int> dfs(int x,int y){
    pair<int,int> d={0,x},e;
    for(auto f:v[x]){
        if(f!=y){
            e=dfs(f,x);
            if(e.ff>d.ff){
                d=e;
            }
        }
    }
    d.ff++;
    return d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i^N;++i){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    c=dfs(1,0);
    c=dfs(c.ss,0);
    cout<<c.ff-1<<"\n";


}