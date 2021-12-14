#include <bits/stdc++.h>
#define sz 200001
using namespace std;

int N,a,b;
vector <int> tab[sz];
bitset <sz> bt;
int wynik;
int dfs(int x){
    bt[x]=1;
    int wn=0;
    priority_queue <int> q;
    for(int i=0;i^tab[x].size();++i){
        if(!bt[tab[x][i]]){
            a= dfs(tab[x][i]);
            if(a){
                q.push(a);
            }
        }
    }
    if(!q.empty()){
        a=q.top();
        q.pop();
        if(!q.empty()){
            b=q.top();
            wynik=max(wynik,a+b);
        }
        q.push(a);
        wn=a+1;
    }
    if(tab[x].size()>2){
        wn=max(wn,1);
        if(!q.empty()){
            a=q.top();
            wn=max(wn,a+1);
            wynik=max(wynik,a);
        }
    }
    bt[x]=0;
    return wn;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i^N;++i){
        cin>>a>>b;
        tab[a].push_back(b);
        tab[b].push_back(a);
    }
    dfs(1);
    cout<<wynik<<"\n";



    return 0;
}

/*
6
1 2
1 3
1 4
4 5
4 6


8
1 3
1 7
3 2
3 8
7 6
6 4
6 5
*/