#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,M,sum,k=0;
int last=40000;
vector<int> v[40001];
string line[201];
vector <int> alls[201][201][2];
//map <pair<pair<int,int>,pair<int,int> >,int> mapa;
vector <int> wyb[2];
bitset<40001> visit;
bitset<40001> kay;
vector <pair<int,pair<int,bool> > > vec[40001];
set <int> st;


void dfs(int x, int zw){
    visit[x]=1;
    wyb[zw].push_back(x);
    for(int i=0;i^v[x].size();++i){
        if(!visit[v[x][i]]){
            dfs(v[x][i],zw^1);
        }
    }
    return;
}

void flow(int x){
    visit[x]=1;
    cout<<"IN "<<x<<"\n";
    if(x==last){
        sum--;
        return;
    }
    for(int i=0;i^vec[x].size();++i){
        if(vec[x][i].ss.ss == kay[vec[x][i].ss.ff] && !visit[vec[x][i].ff]){
            flow(vec[x][i].ff);
            kay[vec[x][i].ss.ff]= !kay[vec[x][i].ss.ff];
        }
    }
    cout<<"Out "<<x<<"\n";
    visit[x]=0;
    return;
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
                        //mapa[{{i-1,z},{i,z}}]=k;
                        alls[i][z][0].push_back(k);
                        alls[i-1][z][0].push_back(k);
                        k++;
                    }
                }
                if(z){
                    if(line[i][z-1]=='#'){
                        //mapa[{{i,z-1},{i,z}}]=k;
                        alls[i][z-1][1].push_back(k);
                        alls[i][z][1].push_back(k);
                        k++;
                    }
                }
            }
        }
    }
    for(int i=0;i^N;++i){
        for(int z=0;z^M;++z){
            for(int j=0;j^alls[i][z][0].size();++j){
                for(int k=0;k^alls[i][z][1].size();++k){
                    v[alls[i][z][0][j]].push_back(alls[i][z][1][k]);
                    v[alls[i][z][1][k]].push_back(alls[i][z][0][j]);
                }
            }
        }
    }
    for(int i=0;i^k;++i){
        if(!visit[i]){
            dfs(i,0);
        }
    }
    k=0;
    for(int i=0;i<wyb[0].size();++i){
        cout<<wyb[0][i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<wyb[1].size();++i){
        cout<<wyb[1][i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i^wyb[0].size();++i){
        vec[1].push_back({wyb[0][i]+2,{k,0}});
        k++;
        for(int z=0;z^v[wyb[0][i]].size();++z){
            vec[wyb[0][i]+2].push_back({v[wyb[0][i]][z]+2,{k,0}});
            vec[v[wyb[0][i]][z]+2].push_back({wyb[0][i]+2,{k,1}});
            k++;
        }
    }
    for(int i=0;i^wyb[1].size();++i){
        vec[wyb[1][i]+2].push_back({last,{k,0}});
        k++;
    }
    visit=0;
    flow(1);

    cout<<sum<<"\n";

    return 0;
}
/*
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