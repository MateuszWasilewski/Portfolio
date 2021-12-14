#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
using namespace std;

int N,a,b,c;
class obj{
public:
    ll waga;
    pair<int,int> pk;
};
obj kr[1000001];
const int half=131072;
ll tree[half*2][2];
vector <pair<int,int> > pol[100001];

pair<int,int> dfs(int x,int y,ll wg){
    int p=a;
    int k=a;
    bool ok=1;
    for(auto e:pol[x]){
        if(e.ff!=y){
            ok=0;
            kr[e.ss].pk=dfs(e.ff,x,wg+kr[e.ss].waga);
            k=max(k,kr[e.ss].pk.ss);
        }
    }
    if(ok){
        tree[half+a][1]=wg;
        tree[half+a][0]=wg;
        a++;
    }
    return {p,k};
}

void actual(int x){
    tree[x][0]=tree[x][1];
    if(x<half)
        tree[x][0]+=max(tree[x*2][0],tree[x*2+1][0]);
    if(x!=1)
        actual(x/2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<N;++i){
        cin>>a>>b>>c;
        pol[a].push_back({b,i});
        pol[b].push_back({a,i});
        kr[i].waga=c;
    }
    a=0;
    dfs(1,0,0);
    for(int i=half-1;i>0;--i){
        tree[i][0]=max(tree[i*2][0],tree[i*2+1][0]);
    }
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>a>>b;
        c=b-kr[a].waga;
        kr[a].waga=b;
        int x=kr[a].pk.ff+half;
        int y=kr[a].pk.ss+half;
        while(x<=y){
            if(x%2){
                tree[x][1]+=c;
                actual(x);
                x++;
            }
            if(!(y%2)){
                tree[y][1]+=c;
                actual(y);
                y--;
            }
            x/=2;
            y/=2;
        }
        cout<<tree[1][0]<<"\n";
    }
}
/*
5
2 1 2
3 1 3
4 3 2
5 3 3
2
2 5
4 1

5
1 2 1
2 3 1
3 4 1
4 5 1
4
1 2
2 3
3 4
4 100

9
1 2 7
2 3 7
2 4 2
4 8 3
1 7 5
1 5 1
5 6 4
5 9 4
5
2 1
1 3
8 8
6 4
8 3

*/