#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

vector <pair<pair<int,int>,pair<int,int> > > v(1,{{0,0},{0,0}});
const int half=262144;
int tree[half*2];
int N,Q;
int a,b,c,test,k,p;

inline void readUI(int *n) //tylko dodatnie
{
    register char c = 0;
    while (c < 33) c=getc_unlocked(stdin);
    (*n) = 0;
    while (c>32) {(*n)=(*n)*10LL + (c-48); c=getc_unlocked(stdin);}
}

inline void putUI(unsigned int n) {
  
	 if(n>0) { //wyłuskanie kolejnych cyfr z liczby n
         putUI(n/10);
         putc_unlocked(n%10+48,stdout);
     }
}

int ask(int lay, int x,int y){
    int ans=0;
    if(lay){
        pair<int,int> e=v[lay].ss;
        p=max(x,e.ff);
        k=min(y,e.ss);
        if(p<=k){
            ans=max(ans, v[lay].ff.ss);
        }
        if(x<e.ff){
            ans=max(ans, ask(v[lay].ff.ff,x,min(y,e.ff-1)));
        }
        if(y>e.ss){
            ans=max(ans, ask(v[lay].ff.ff,max(e.ss+1,x),y));
        }
    }
    else{
        x+=half;
        y+=half;
        while(x!=y && x!=y-1){
            if(x%2){
                ans=max(ans, tree[x]);
                x++;
            }
            if(!(y%2)){
                ans=max(ans, tree[y]);
                y--;
            }
            x/=2;
            y/=2;
        }
        ans=max(ans, tree[x]);
        if(x!=y)
            ans=max(ans, tree[y]);
    }
    return ans;
}


int main(){
    cin>>N>>Q;
    for(int i=1; i<=N; ++i){
        readUI(&tree[i+half]);
    }
    for(int i=half-1; i>0; --i){
        tree[i]=max(tree[i*2],tree[i*2+1]);
    }
    for(int i=0; i<Q; ++i){
        readUI(&test);
        if(test){
            readUI(&p);
            readUI(&a);
            readUI(&b);
            //cin>>p>>a>>b;
            cout<<ask(p,a,b)<<"\n";
        }
        else{
            readUI(&k);
            readUI(&a);
            readUI(&b);
            readUI(&c);
            //cin>>k>>a>>b>>c;
            v.push_back({{k,c},{a,b}});
        }
    }
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