#include <bits/stdc++.h>
#define sz 300001
using namespace std;

int N,a,b;
int w=0;
string word;
vector <int> pol[sz];
bitset <sz> visit;

void dfs(int x,int score){
    visit[x]=1;
    if(word[x-1]=='('){
        score++;
    }
    else{
        score--;
    }
    if(score==0){
        w++;
    }
    else if(score<0){
        visit[x]=0;
        return;
    }
    for(int i=0;i<pol[x].size();++i){
        if(!visit[pol[x][i]]){
            dfs(pol[x][i],score);
        }
    }
    visit[x]=0;
    return;
}  

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cin>>word;
    for(int i=1;i^N;++i){
        cin>>a>>b;
        pol[a].push_back(b);
        pol[b].push_back(a);
    }
    for(int i=1;i<=N;++i){
        dfs(i,0);
    }
    cout<<w<<"\n";
}

/*
5
())((
1 2
2 3
2 4
3 5

*/