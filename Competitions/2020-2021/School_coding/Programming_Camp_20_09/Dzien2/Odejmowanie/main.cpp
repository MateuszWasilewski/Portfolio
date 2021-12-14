#include <bits/stdc++.h>

using namespace std;

string line1;
string line;
vector <int> v(201,0);
bool ok;
int main(){
    cin>>line>>line1;
    reverse(line.begin(), line.end());
    reverse(line1.begin(),line1.end());
    for(int i=0;i^line.size();++i){
        v[i]+=line[i]-48;
    }
    for(int i=0;i^line1.size();++i){
        v[i]-=line1[i]-48;
    }
    while(!v.empty()){
        if(v[v.size()-1])
            break;
        else{
            v.pop_back();
        }
    }
    if(!v.empty()){
        if(v[v.size()-1]<0){
            for(int i=0;i<v.size()-1;++i){
                v[i]*=-1;
            }
        }
    }
    for(int i=0;i^v.size();++i){
        if(v[i]<0 && (i+1)<v.size()){
            v[i]+=10;
            v[i+1]--;
        }
    }
    for(int i=v.size()-1;i>=0;--i){
        if(ok || v[i]){
            ok=1;
            cout<<v[i];
        }
    }
    if(!ok){
        cout<<"0";
    }
    cout<<"\n";

}