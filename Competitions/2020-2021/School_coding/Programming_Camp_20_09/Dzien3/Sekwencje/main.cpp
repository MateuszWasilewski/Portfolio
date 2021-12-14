#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,odp=INT_MAX;
string word;
vector <pair<int,int> >v; 
set <pair<int,int>> st;
int k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i^N;++i){
        cin>>word;
        k=0;
        for(int z=0;z^word.size();++z){
            k<<=1;
            k+=(word[z]-48);
            //cout<<k<<"\n";
        }
        v.push_back({word.size(),k});
        if(st.find({word.size(),k})==st.end())
            st.insert({word.size(),k});
        else if(odp>word.size())
            odp=word.size();
            
    }
    st.insert({0,0});
    sort(v.begin(),v.end());
    for(auto f:st){
        bool ok=1;
        for(int i=0;i<v.size()&&ok;++i){
            auto e=v[i];
            if(e.ff+f.ff<16){
                pair<int,int> b,c;
                b={e.ff+f.ff,(e.ss<<f.ff)+f.ss};
                st.insert(b);
                /*if(st.find(b)==st.end())
                    st.insert(b);
                else if (b.ff<odp)
                    odp=b.ff;*/
                c={e.ff+f.ff,(f.ss<<e.ff)+e.ss};
                st.insert(c);
                /*if(c.ss^b.ss){
                    if(st.find(c)==st.end())
                        st.insert(c);
                    else if (c.ff<odp)
                        odp=c.ff;
                }*/
            }
            else
                ok=0;
        }
    }
    for(auto e:st){
        if(e.ff<4)
            cout<<e.ff<<" "<<e.ss<<"\n";
    }
    pair<int,int> c,d;
    for(int i=0;i<v.size();++i){
        for(int z=i+1;z<v.size();++z){
            c=v[i];
            d=v[z];
            if(c.ff<d.ff)
                swap(c,d);
            for(int j=0;j<d.ff;++j){
                
            }

        }
    }
    if(odp==INT_MAX)
        cout<<0<<"\n";
    else
        cout<<odp<<"\n";
}

/*
3
0
01
10

3
00
10
1
*/