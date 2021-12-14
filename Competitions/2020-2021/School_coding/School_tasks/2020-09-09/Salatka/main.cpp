#include <bits/stdc++.h>

using namespace std;

int const half=1<<17;
int N,a,b,t;
int tab[half][2];
int tree[half<<1];

void update(int x){
    x/=2;
    tree[x]=tree[x*2]+tree[x*2+1];
    if(x!=1){
        update(x);
    }
}
void check(int x){
    if(tab[x][0]^tab[x][1]){
            tree[half+x]=1;
    }
    else{
        tree[half+x]=0;
    }
    update(half+x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<2;++i){
        for(int z=0;z<N;++z){
            cin>>tab[z][i];
        }
    }
    for(int i=0;i<N;++i){
        if(tab[i][0]^tab[i][1]){
            tree[half+i]=1;
        }
        else{
            tree[half+i]=0;
        }
        update(half+i);
    }
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>t>>a>>b;
        a--;
        if(t){
            int x=a+half,y=b+half-1;
            int wyn=0;
            while(x!=y-1 && x!=y){
                if(x%2==0){
                    x/=2;
                }
                else{
                    wyn+=tree[x];
                    x++;
                    x/=2;
                }
                if(y%2==0){
                    wyn+=tree[y];
                    y--;
                    y/=2;
                }
                else{
                    y/=2;
                }
            }
            wyn+=tree[x];
            if(x!=y){
                wyn+=tree[y];
            }
            cout<<wyn<<"\n";
        }
        else{
            tab[a][0]=b;
            check(a);
        }
    }
}

/*
5
1 2 3 4 5
5 4 3 2 1
4
1 1 3
1 2 4
0 3 4
1 1 5


3
1 490 2094
4 23 4
5
1 1 1
1 2 2
1 3 3
0 2 23
1 1 3
*/