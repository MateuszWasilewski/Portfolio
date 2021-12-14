#include <bits/stdc++.h>

using namespace std;
string line;
int wynik,now,mn;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>line;
    for(int i=0;i<line.size();++i){
        if(line[i]=='-'){
            mn++;
        }
        else{
            if(mn%2){
                wynik=max(wynik, now+mn/2);
                now=mn/2;
                mn=0;
            }
            else{
                now+=mn/2;
                mn=0;
            }
            now++;
        }
    }
    wynik=max(wynik, now+mn/2);
    cout<<wynik<<"\n";
    return 0;
}