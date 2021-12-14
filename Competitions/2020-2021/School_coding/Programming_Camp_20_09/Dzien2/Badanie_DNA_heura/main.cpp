#include <bits/stdc++.h>

using namespace std;

int N,Q,a,b,c,p,k;
const int half=262144;
int tree[half*2];
class obj{
public:
    int fath=-1;
    int p=0;
    int k=0;
    int c=0;
};
vector <obj> v;

int maxi(int x,int y){
    int odp=0;
    x+=half;
    y+=half;
    while(x!=y && x!=y-1){
        if(x%2){
            odp=max(odp,tree[x]);
            x++;
        }
        if(!(y%2)){
            odp=max(odp,tree[y]);
            y--;
        }
        x/=2;
        y/=2;
    }
    odp=max(odp,tree[x]);
    if(x!=y)
        odp=max(odp,tree[y]);
    return odp;
}

int ask(int a,int ll,int pp){
    int odp=0;
    
    if(!a)
        return maxi(ll,pp);

    if(max(ll,v[a].p)<=min(pp,v[a].k))
        odp=max(odp,v[a].c);

    if(ll<v[a].p)
        odp=max(odp,ask(v[a].fath,ll,v[a].p-1));
    
    if(pp>v[a].k)
        odp=max(odp,ask(v[a].fath,v[a].k+1,pp));

    return odp;
}

int main(){
    cin.tie(0);
    cin>>N>>Q;
    for(int i=1;i<=N;++i){
        cin>>tree[half+i];
    }
    for(int i=half-1;i>0;--i){
        tree[i]=max(tree[i*2],tree[i*2+1]);
    }
    obj ob1;
    v.push_back(ob1);

    for(int i=0;i^Q;++i){
        cin>>a;
        if(a){
            cin>>a>>p>>k;
            cout<<ask(a,p,k)<<"\n";
        }
        else{
            cin>>a>>p>>k>>c;
            obj ob;
            ob.fath=a;
            ob.p=p;
            ob.k=k;
            ob.c=c;
            v.push_back(ob);
        }
    }
    return 0;
}
/*
6 7
3 5 2 4 6 3
1 0 2 4
0 0 1 3 7
0 0 3 5 1
1 1 3 6
1 2 2 5
0 1 2 4 3
1 3 2 6
*/