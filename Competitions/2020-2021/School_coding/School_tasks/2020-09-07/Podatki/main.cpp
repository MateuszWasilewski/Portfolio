#include <bits/stdc++.h>

using namespace std;
int wynik=0,a,n;
priority_queue <int> q;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a;
        q.push(a);
    }
    int k=1;
    while(true){
        a=q.top();
        q.pop();
        if(a<k){
            cout<<wynik<<"\n";
            return 0;
        }
        else{
            wynik+=k;
            q.push(a-k);
        }
        k ^=3;
    }
}