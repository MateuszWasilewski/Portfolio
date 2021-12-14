#include <bits/stdc++.h>

using namespace std;

int N,maxi,a;
bool ok;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i^N;++i){
        cin>>a;
        maxi=max(a,maxi);
        if(a==1 && N==2){
            ok=1;
        }
    }
    if(ok){
        ok=((maxi-1)%2);
    }
    else{
        ok=(maxi%2);
    }

    if(ok){
        cout<<"Pedia\n";
    }
    else{
        cout<<"Wiki\n";
    }
    return 0;
}