#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,M,Q,t,a;
int tab[100003];
pair <int,int> d;
set <pair<int,int> > st;
priority_queue <pair<int,int> > q;

void calc(){
    while(!q.empty()){
        d=q.top();
        q.pop();
        if(d.ss==N){
            tab[d.ss]++;
        }
        else{
            tab[d.ss]=min(tab[d.ss]+1,tab[d.ss+1]);
            if(st.find({d.ff-1,d.ss+1})==st.end()){
                tab[d.ss+1]=tab[d.ss];
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>Q;
    for(int i=1; i<=N; ++i){
        cin>>t;
        for(int z=0; z^t; ++z){
            cin>>a;
            q.push({a,i});
            st.insert({a,i});
        }
    }
    calc();
    for(int i=0; i^Q; ++i){
        cin>>a;
        cout<<tab[a]<<"\n";
    }


    return 0;
}

/*
3 9 3
1 6
2 3 8
2 5 7
3
2
1

5 20 5
1 16
3 7 15 18
3 6 9 14
3 3 8 11
2 2 5
1
2
3
4
5


*/