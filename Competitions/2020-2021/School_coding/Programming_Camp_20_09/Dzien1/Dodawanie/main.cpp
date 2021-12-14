#include <bits/stdc++.h>

using namespace std;

string line1;
string line;
int k=0;
vector <int> v;
int main(){
    cin>>line>>line1;
    reverse(line.begin(), line.end());
    reverse(line1.begin(),line1.end());
    while(true){
        if(v.size()==k){
            v.push_back(0);
        }
        if(line.size()>k){
            v[k]+=line[k]-48;
        }
        if(line1.size()>k){
            v[k]+=line1[k]-48;
        }
        if(v[k]==0){
            v.pop_back();
            break;
        }
        if(v[k]>9){
            v.push_back(v[k]/10);
            v[k]%=10;
        }
        k++;
    }
    for(int i=v.size()-1;i>=0;--i){
        cout<<v[i];
    }
    cout<<"\n";
}