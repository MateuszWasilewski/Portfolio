#include <bits/stdc++.h>

using namespace std;
int N,Q,wynik,a,b;
string word;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    cin>>word;
    for(int i=0; i^Q; ++i){
        cin>>a>>b;
        if(word[a-1]=='J' && word[b-1]=='J') wynik++;
    }
    cout<<wynik<<"\n";
    return 0;
}