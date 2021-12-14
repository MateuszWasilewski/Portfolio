#include <bits/stdc++.h>
#define ss second
#define ff first
using namespace std;

int n,k,p,a;
set <int> st;
vector <int> v;
int tab[100001];
int odl[500001];
int wynik;
priority_queue <pair<int,int> > q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k>>p;
    for(int i=0;i<p;++i){
        cin>>a;
        v.push_back(a);
    }
    for(int i=p-1;i>=0;--i){
        odl[i]=tab[v[i]];
        tab[v[i]]=i;
    }
    for(int i=0;i<p;++i){
        if(st.size()<k){
            st.insert(v[i]);
            q.push({odl[i],v[i]});
            wynik++;
        }
        else{
            if(st.find(v[i])==st.end()){
                pair<int,int> b=q.top();
                q.pop();
                q.push({odl[i],v[i]});
                if(b.ss!=v[i]){
                    st.erase(b.ss);
                    st.insert(v[i]);
                    wynik++;
                }
            }
        }
    }
    cout<<wynik<<"\n";

}