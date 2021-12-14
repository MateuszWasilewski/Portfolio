#include <bits/stdc++.h>
using namespace std;
int N;
int a,k;
bool ok=1,odp;
vector <int> v;
bool comp(int x,int y){
    return (x>y);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i^N;++i){
        cin>>a;
        v.push_back(a-1);
    }
    v.push_back(-1);
    sort(v.begin(),v.end(),comp);
    while(ok){
        if(v[k+1]<k+1){
            ok=0;
            odp= odp | (v[k]-k)%2;
        }
        if(k==v[k] || !ok){
            int b=1;
            ok=0;
            while(v[k+b]==k){
                b++;
            }
            odp= odp | ((b-1)%2);
        }
        k++;
    }
    if(odp){
        cout<<"Wiki\n";
    }
    else{
        cout<<"Pedia\n";
    }
    return 0;
}