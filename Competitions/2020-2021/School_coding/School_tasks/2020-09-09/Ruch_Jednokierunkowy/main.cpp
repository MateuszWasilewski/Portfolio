#include <bits/stdc++.h>
#define ss second
#define ff first
using namespace std;

int a,b,N,wynik;
vector <pair<int,int> > v[250001];
int tab[250001];
set <int> st;

int depth(int x,int y){
    tab[x]=1;
    for(int i=0;i<v[x].size();++i){
        if(v[x][i].ff!=y){
            v[x][i].ss=depth(v[x][i].ff,x);
            tab[x]+=v[x][i].ss;
        }
    }
    return tab[x];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<N;++i){
        cin>>a>>b;
        v[a].push_back({b,0});
        v[b].push_back({a,0});
    }
    cout<<N-1<<" ";
    depth(1,1);
    int x=1;
    bool ok=1;
    int last=0;
    while(ok){
        for(int i=0;i<v[x].size() && ok;i++){
            if(v[x][i].ss>N/2){
                ok=0;
                tab[x]-=v[x][i].ss;
                tab[v[x][i].ff]+=tab[x];
                last=tab[x];
                x=v[x][i].ff;
            }
        }
        ok=!ok;
    }
    wynik=N-1;
    st.insert(last);
    for(int i=0;i<v[x].size();++i){
        if(v[x][i].ss){
            for(auto poz=st.rbegin();poz!=st.rend();poz++){
                st.insert(*poz+v[x][i].ss);
            }
        }
    }
    int k=0;
    for(auto poz=st.begin();poz!=st.end();poz++){
        if(*poz<=N/2){
            k=*poz;
        }
        else{
            break;
        }
    }
    wynik+=k*(N-k-1);
    cout<<wynik<<"\n";


    return 0;
}
/*
4
1 2
1 3
1 4

8
1 2
2 3
3 4
4 5
5 6
6 7
7 8
*/