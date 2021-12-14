#include <bits/stdc++.h>
#define ss second
#define ff first
#define ll long long
using namespace std;

string word;
vector <pair<int, vector<int> > > vec;
vector <int> v;
const int half=524288;
ll tree[half*2][2];
ll odp=0;

void add(int x,int y,ll c,int nb){
    while(x!=y && x!=y-1){
        if(x%2==0){
            x/=2;
        }
        else{
            tree[x][nb]+=c;
            x++;
            x/=2;
        }
        if(y%2==0){
            tree[y][nb]+=c;
            y--;
            y/=2;
        }
        else{
            y/=2;
        }
    }
    tree[x][nb]+=c;
    if(x!=y){
        tree[y][nb]+=c;
    }
    return;
}
ll bonus(int x,int nb){
    ll bon=0;
    while(true){
        bon+=tree[x][nb];
        if(x==1){break;}
        x/=2;
    }
    return bon;
}

void calc(int x,ll wn){
    odp=max(odp,wn);
    if(x==16){
        return;
    }
    calc(x+1,wn);
    for(int i=0;i<vec[x].ss.size();++i){
        add(half+vec[x].ss[i],half*2-1,-1,0);
        wn+=bonus(half+vec[x].ss[i],0);
        wn-=bonus(half+vec[x].ss[i],1);
        add(half,half+vec[x].ss[i], 1,1);
    }
    calc(x+1,wn);
    for(int i=0;i<vec[x].ss.size();++i){
        add(half+vec[x].ss[i],half*2-1,1,0);
        add(half,half+vec[x].ss[i],-1,1);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>word;
    for(int i=0;i^16;++i){
        vec.push_back({0,v});
    }
    for(int i=0;i^word.size();++i){
        vec[word[i]-97].ff--;
        vec[word[i]-97].ss.push_back(i);
        add(half+i,half*2-1,1,0);
    }
    sort(vec.begin(),vec.end());
    calc(0,0);
    cout<<odp<<"\n";
    return 0;
}