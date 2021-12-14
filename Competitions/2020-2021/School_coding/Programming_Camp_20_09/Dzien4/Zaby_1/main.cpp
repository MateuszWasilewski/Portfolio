#include <bits/stdc++.h>
#define ff first
#define ss second
#define pairs pair<int,pair<pair<int,int>,pair<int,int>>>
using namespace std;

int N,M,px,py,kx,ky,Q,x,y,odp;
pair<int,int> a,b;
int tab[1002][1002];
bool visit[1002][1002];
priority_queue < pairs , vector <pairs>, greater<pairs> >bomb;
priority_queue <pair<int,pair<int,int> > > q;

void pot_add(pair<int,int> c, int x1,int y1){
    if(tab[x1][y1]==INT_MAX){
        x=abs(x1-c.ff);
        y=abs(y1-c.ss);
        int wn=x*x+y*y;
        tab[x1][y1]=wn;
        bomb.push({wn,{c,{x1,y1}}});
    }
}
void add(int x1, int y1, int maxi){
    if(!visit[x1][y1] && tab[x1][y1]!=INT_MAX){
        visit[x1][y1]=1;
        q.push({min(maxi,tab[x1][y1]),{x1,y1}});
    }
}

int Djikstra(){
    while(!q.empty()){
        auto c=q.top();
        q.pop();
        a=c.ss;
        if(a==make_pair(kx,ky))
            return c.ff;
        add(a.ff-1,a.ss,c.ff);
        add(a.ff+1,a.ss,c.ff);
        add(a.ff,a.ss-1,c.ff);
        add(a.ff,a.ss+1,c.ff);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    cin>>px>>py>>kx>>ky;
    for(int i=1; i<=N; ++i){
        for(int z=1; z<=M; ++z){
            tab[i][z]=INT_MAX;
        }
    }
    cin>>Q;
    for(int i=0; i^Q; ++i){
        cin>>x>>y;
        tab[x][y]=0;
        bomb.push({0,{{x,y},{x,y}}});
    }
    while(!bomb.empty()){
        auto c=bomb.top();
        bomb.pop();
        a=c.ss.ff;
        b=c.ss.ss;
        pot_add(a,b.ff-1,b.ss);
        pot_add(a,b.ff+1,b.ss);
        pot_add(a,b.ff,b.ss-1);
        pot_add(a,b.ff,b.ss+1);
    }
    /*for(int i=1;i<=N;++i){
        for(int z=1;z<=M;++z){
            cout<<tab[i][z]<<" ";
        }
        cout<<"\n";
    }*/
    q.push({tab[px][py],{px,py}});
    //odp=sqrt(Djikstra());
    cout<<Djikstra()<<"\n";


    return 0;
}

/*
5 5
1 1 5 5
2
3 3
4 2
*/