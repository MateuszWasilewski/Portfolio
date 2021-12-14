#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int N,M,t,a,b,k,c;
int last,wynik;
vector <int> boys;
vector <int> girls;
vector <pair<pair<int,int>,pair<int,bool> > > pol[502];
bitset <1501> way;
bitset <1501> inq;
int tab[502][3];

bool flows(){
    queue <int> q;
    inq=0;
    q.push(0);
    inq[0]=1;
    tab[0][0]=0;
    tab[0][1]=-1;
    tab[0][2]=-1;
    for(int i=1;i<=last;++i){
        tab[i][0]=INT_MAX;
    }
    while(!q.empty()){
        a=q.front();
        q.pop();
        inq[a]=0;
        for(int i=0;i<pol[a].size();++i){
            if(pol[a][i].ss.ss == way[pol[a][i].ss.ff]){
                b=pol[a][i].ff.ss;
                if(tab[a][0]+pol[a][i].ff.ff<tab[b][0]){
                    tab[b][0]=tab[a][0]+pol[a][i].ff.ff;
                    tab[b][1]=a;
                    tab[b][2]=pol[a][i].ss.ff;
                    if(!inq[b]){
                        q.push(b);
                        inq[b]=1;
                    }
                }
            }
        }
    }
    if(tab[last][0]==INT_MAX){
        return 0;
    }
    int a=tab[last][1];
    int b=tab[last][2];
    wynik+=tab[last][0];
    //cout<<tab[last][0]<<"\n";
    while(a!=-1){
        way[b].flip();
        b=tab[a][2];
        a=tab[a][1];

    }
    return 1;
}


/*bool flow(int x){
    visit[x]=1;
    if(x==last){
        visit[x]=0;
        return 1;
    }
    bool ok=0;
    for(int i=0; i^pol[x].size() && !ok; ++i){
        if((pol[x][i].ss.ss == way[pol[x][i].ss.ff]) && !visit[pol[x][i].ff.ss]){
            ok=flow(pol[x][i].ff.ss);
            if(ok){
                wynik+=pol[x][i].ff.ff;
                way[pol[x][i].ss.ff] = !way[pol[x][i].ss.ff];
            }
        }
        if(!ok){
            skip[x]++;
        }
    }

    visit[x]=0;
    return ok;
}*/



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>t;
    girls.push_back(0);
    boys.push_back(0);
    last=N+M+1;
    for(int i=1; i<=N; ++i){
        cin>>a;
        girls.push_back(a);
        pol[0].push_back({{0,i},{k,0}});
        //pol[i].push_back({{0,0},{k,1}});
        k++;
    }
    for(int i=1; i<=M; ++i){
        cin>>a;
        boys.push_back(a);
        pol[N+i].push_back({{0,last},{k,0}});
        //pol[last].push_back({{0,N+i},{k,1}});
        k++;
    }
    for(int i=0; i^t; ++i){
        cin>>a>>b;
        c=abs(girls[a]-boys[b]);
        pol[a].push_back({{c,N+b},{k,0}});
        pol[N+b].push_back({{-c,a},{k,1}});
        k++;
    }
    /*for(int i=0; i<=last; ++i){
        sort(pol[i].begin(),pol[i].end());
        cout<<i<<"\n";
        for(auto z:pol[i]){
            cout<<z.ff.ff<<" ";
        }
        cout<<"\n";
    }*/

    while(flows());
    cout<<wynik<<"\n";

    /*for(int i=0;i<k;++i){
        if(!way[i]){
            cout<<i<<"\n";
        }
    }*/

}

/*
6 8 13
1 3 7 8 12 15
21 2 8 3 2 4 15 18
1 1
1 3
2 2
2 3
3 3
3 5
4 3
4 4
5 5
5 6
5 7
6 6
6 8

5 5 5
1 1 1 1 1
2 2 2 2 2
1 1
2 2
3 3
4 4
5 5

3 3 6
1 2 3
4 5 6
1 1
1 2
1 3
2 3
3 2
3 3
*/