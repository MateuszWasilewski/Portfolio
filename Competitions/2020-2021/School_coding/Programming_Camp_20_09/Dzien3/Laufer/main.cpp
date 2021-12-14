#include <bits/stdc++.h>

using namespace std;

int t;
string line;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for(int i=0;i^t;++i){
        cin>>line;
        if(line.size()==1 && line[line.size()-1]<'3'){
            cout<<line<<"\n";
        }
        else{
            vector <int> v;
            v.clear();
            for(int i=line.size()-1;i>=0;--i){
                v.push_back((line[i]-48)*2);
            }
            v[0]-=2;
            for(int i=0;i<v.size();++i){
                if(v[i]>9){
                    if(!(i+1<v.size())){
                        v.push_back(0);
                    }
                    v[i+1]+=v[i]/10;
                    v[i] %=10;
                }
                if(v[i]<0){
                    v[i]+=10;
                    v[i+1]--;
                }
            }
            for(int i=v.size()-1;i>=0;--i){
                cout<<v[i];
            }
            cout<<"\n";
        }
    }


}