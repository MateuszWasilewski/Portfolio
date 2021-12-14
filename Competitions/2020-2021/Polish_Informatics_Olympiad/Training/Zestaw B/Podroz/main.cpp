#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,k,g,m,t,x,y,t1,n,c,a;
int odl[1001];
vector <pair<int,pair<int,int> > > vec[1001];
priority_queue <pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> k >> x >> y >> g >> m;
    for(int i=0; i<k; ++i){
        cin >> n >> c;
        int suma=0;
        vector <int> v;
        vector <int> cost;
        for(int z=0; z<n; ++z){
            cin >> a;
            v.push_back(a);
        }
        for(int z=1; z<n; ++z){
            cin >> a;
            cost.push_back(a);
        }
        suma = 0;
        for(int z=0; z<n-1; ++z){
            vec[v[z]].push_back({v[z+1],{suma,cost[z]}});
            suma = (suma + cost[z]) % c;
        }
        suma = 0;
        for(int z=v.size()-1; z>0; --z){
            vec[v[z]].push_back({v[z-1],{suma,cost[z-1]}});
            suma = (suma + cost[z-1]) % c;
        }
    }

    t1 = g*60 + m;
    q.push({t1,x});
    for(int i=0; i<=N; ++i){
        odl[i] = INT32_MAX;
    }
    odl[x] = t1;
    while(!q.empty()){
        auto e = q.top();
        q.pop();
        if(odl[e.ss] == e.ff){
            for(auto f:vec[e.ss]){
                int time = e.ff;
                int hp = time % 60;
                if(e.ff % f.ss.ff){
                    time += (f.ss.ff-(e.ff%f.ss.ff));
                }
                time += f.ss.ss;
                if(time < odl[f.ff]){
                    odl[f.ff] = time;
                    q.push({time, f.ff});
                }
            }
        }
    }
    t1 = odl[y];
    cout << (t1/60) % 24 << " " << t1 % 60 << "\n";
}
/*
6 2 5 6 23 30
4 15
1 3 4 6
9 12 10
4 20
5 3 4 2
11 17 11



*/