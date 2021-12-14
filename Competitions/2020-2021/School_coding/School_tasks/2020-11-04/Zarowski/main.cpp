#include <bits/stdc++.h>

using namespace std;

bitset<1000001> bt;
int N,wynik,a,Q;
string line;

void func(int x){
    if(bt[x]){
        bt[x]=0;
        if(x>0)
            wynik--;
    }
    else{
        bt[x]=1;
        if(x>0)
            wynik++;
    }
}

int main(){
    cin>>N>>Q;
    cin>>line;
    for(int i=0; i<N; ++i){
        if(line[i]=='1'){
            func(i);
            func(i+1);
        }
    }
    cout<<wynik<<"\n";
    for(int i=0; i^Q; ++i){
        cin>>a;
        func(a);
        func(a-1);
        cout<<wynik<<"\n";
    }
}