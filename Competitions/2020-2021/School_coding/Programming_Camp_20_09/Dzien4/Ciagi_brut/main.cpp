#include <bits/stdc++.h>
#define ff first
#define ss second
#define sh short int
using namespace std;

sh N,M,a;
pair<pair<sh,sh>,pair<sh,sh> > c;
queue <pair<pair<sh,sh>,pair<sh,sh> > >q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    q.push({{0,0},{0,0}});
    for(int i=0; i<N && !q.empty(); ++i){
        cin>>a;
        while(!q.empty()){
            c=q.front();
            if(c.ff.ff+c.ff.ss==i){
                q.pop();
                if(a>c.ss.ff && c.ff.ff<M){
                    q.push({{c.ff.ff+1,c.ff.ss},{a,c.ss.ss}});
                }
                if(a>c.ss.ss && c.ff.ss<M){
                    q.push({{c.ff.ff,c.ff.ss+1},{c.ss.ff,a}});
                }
            }
            else
                break;
        }
    }
    cout<<q.size()<<"\n";
}
/*
6 3
1 3 4 2 6 5
*/