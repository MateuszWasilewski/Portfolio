#include <bits/stdc++.h>
#define ff first
#define ss second
#define sh short
using namespace std;

int N,a,r,wynik=1;
vector <int> v;
set <int> st;
priority_queue <pair<sh,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
set <pair<sh,int> > use;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i^N;++i){
        cin>>a;
        v.push_back(a);
        st.insert(a);
    }
    sort(v.begin(),v.end());
    for(int i=0;i^N;++i){
        while(!q.empty()){
            if(q.top().ff==i){
                use.erase(q.top());
                q.pop();
            }
            else
                break;
        }
        for(int z=i+1;z^N;++z){
            a=v[z];
            r=v[z]-v[i];
            if(use.find({a,r}) == use.end()){
                int k=1;
                while(st.find(a)!=st.end()){
                    a+=r;
                    use.insert({a,r});
                    q.push({a,r});
                    k++;
                }
                wynik=max(wynik,k);
            }
        }
    }
    cout<<wynik<<"\n";
}