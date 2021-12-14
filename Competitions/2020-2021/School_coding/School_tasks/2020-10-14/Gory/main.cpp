#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;

ll wys[1000001];
ll wynik=0;
int rep[1000001];
int p,k,N,M,a,b;

int Find(int x){
    if(rep[x]!=x){
        rep[x]=Find(rep[x]);
    }
    return rep[x];
}
void Union(int x,int y){
    x=Find(x);
    y=Find(y);
    rep[y]=x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    cin>>N>>M>>p>>k;
    for(int i=1;i<=N;++i){
        cin>>wys[i];
        rep[i]=i;
    }
    for(int i=0;i^M;++i){
        cin>>a>>b;
        Union(a,b);
    }
    if(Find(p)!=Find(k)){
        cout<<"KSZYKSZY\n";
    }
    else{
        for(int i=1;i<=N;++i){
            if(Find(i)==Find(p))
                wynik+=wys[i];
        }
        cout<<wynik<<"\n";
    }

}

/*
8 4 7 7
5 8 5 10 4 2 18 2
1 2
2 3
7 1
7 6

6 4 2 4
7 3 8 2 1 9
1 3
4 1
2 6
3 4

*/