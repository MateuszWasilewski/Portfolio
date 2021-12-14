#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,M;
int sum=0;
int k=2,p=1;
int last=40000;
string line[201];
vector <int> alls[201][201][2];
vector <pair<int,pair<int,bool> > > v[40001];
bitset <4000001> bt;
bitset <40001> visit;
int tab[40001];
bool flow(int x){
    visit[x]=1;
    if(x==last){
        sum--;
        visit[x]=0;
        return 1;
    }
    bool ok=0;
    for(int i=0;i^v[x].size()&& !ok;++i){
        if((bt[v[x][i].ss.ff]==v[x][i].ss.ss) && !visit[v[x][i].ff]){
            ok= flow(v[x][i].ff);
            if(ok){
                bt[v[x][i].ss.ff]= !bt[v[x][i].ss.ff];
            }
            else{
                tab[x]++;
            }
        }
    }

    visit[x]=0;
    return ok;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i^N;++i){
        cin>>line[i];
    }
    for(int i=0;i^N;++i){
        for(int z=0;z^M;++z){
            if(line[i][z]=='#'){
                sum++;
                if(i){
                    if(line[i-1][z]=='#'){
                        alls[i-1][z][0].push_back(k);
                        alls[i][z][0].push_back(k);
                        v[1].push_back({k,{p,0}});
                        v[k].push_back({1,{p,1}});
                        p++;
                        k++;
                    }
                }
                if(z){
                    if(line[i][z-1]=='#'){
                        alls[i][z-1][1].push_back(k);
                        alls[i][z][1].push_back(k);
                        v[k].push_back({last,{p,0}});
                        v[last].push_back({k,{p,1}});
                        p++;
                        k++;
                    }
                }
            }
        }
    }
    for(int i=0;i^N;++i){
        for(int z=0;z^M;++z){
            for(int j=0;j^alls[i][z][0].size();++j){
                for(int t=0;t^alls[i][z][1].size();++t){
                    v[alls[i][z][0][j]].push_back({alls[i][z][1][t],{p,0}});
                    v[alls[i][z][1][t]].push_back({alls[i][z][0][j],{p,1}});
                    p++;
                }
            }
        }
    }
    for(int i=2;i^k;++i){
        if(v[i].size()==1){
            sum--;
        }
    }
    while(flow(1));
    cout<<sum<<"\n";

    return 0;
}

/*
3 3
###
#.#
###

3 4
#.##
####
##..

6 6
######
##....
######
##...#
##...#
######

10 8
####..##
#..#.##.
#..#.###
####.#.#
....####
.###.###
###.#..#
########
###..###
.##.###.
*/