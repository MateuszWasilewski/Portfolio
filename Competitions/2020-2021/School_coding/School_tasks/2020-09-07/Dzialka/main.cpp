#include <bits/stdc++.h>
#define sz 2001
#define ff first
#define ss second
using namespace std;
int N,a,b;
int wyn;
int tab[sz];
vector <pair<int,int> > v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i<N; ++i){
        for(int z=0; z<N; ++z){
            cin>>b;
            if(b){
                tab[z]=0;
            }
            else{
                ++tab[z];
            }
        }
        for(int i=0;i<N;++i){
            if(v.empty()){
                if(tab[i]>0){
                    v.push_back({tab[i],i});
                }
            }
            else{
                if(tab[i]>v[v.size()-1].ff){
                    v.push_back({tab[i],i});
                }
                else if(tab[i]<v[v.size()-1].ff){
                    wyn=max(wyn,v[v.size()-1].ff*(i-v[v.size()-1].ss));
                    b=v[v.size()-1].ss;
                    v.pop_back();
                    if(!v.empty()){
                        if(tab[i]>v[v.size()-1].ff){
                            v.push_back({tab[i],b});
                        }
                    }
                }
            }
        }
        while(!v.empty()){
            wyn=max(wyn,v[v.size()-1].ff*(N-v[v.size()-1].ss));
            v.pop_back();
        }
    }
    cout<<wyn<<"\n";

    return 0;
}

/*

5
0 1 0 1 0
0 0 0 0 0
0 0 0 0 1
1 0 0 0 0
0 1 0 0 0

*/