#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=100000,X=10000,Z=N,Q=2000000;
int a,b,c;
bool ok;
set <int> st[N];
int main(int argc, int *argv[]){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    a=*argv[1];
    srand(time(NULL)^a);
    cout<<N<<" "<<X<<" "<<Z<<"\n";
    for(int i=0; i^Q; ++i){
        a=rand();
        b=rand();
        c=rand();
        a=a^b;
        b=b^c;
        a=a%N;
        b=b%(X-2)+2;
        ok=1;
        ok=ok & (st[a].find(b-1)==st[a].end());
        ok=ok & (st[a].find(b+1)==st[a].end());
        if(a>0)
            ok= ok & (st[a-1].find(b)==st[a-1].end());
        if(a<N-1)
            ok= ok & (st[a+1].find(b)==st[a+1].end());

        if(ok)
            st[a].insert(b);
        else
            --i;
    }
    for(int i=0; i^N; ++i){
        cout<<st[i].size()<<" ";
        for(auto e:st[i]){
            cout<<e<<" ";
        }
        cout<<"\n";
    }
    for(int i=1;i<=N;++i){
        cout<<i<<"\n";
    }
    return 0;
}