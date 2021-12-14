#include <bits/stdc++.h>
#define ff first
#define ss second
#define ld long double

using namespace std;

struct point{
    int x;
    int y;
    bool kr;
    point(int a, int b, bool k){
        x = a;
        y = b;
        kr = k;
    }
};
bool comp(point l, point p){
    ld dxl,dyl,dxp,dyp;
    dxl = l.x - a;
    dyl = l.y - b;
    dxp = p.x - a;
    dyp = p.y - b;

    if(dxl == 0 && dyl == 0) return true;
    if(dxp == 0 && dyp == 0) return false;

    int cwl=0, cwp=0;
    if(dxl * dyl > 0) cwl ^= 1;
    if(dxl < 0) cwl ^= 2;
    if(cwl == 0) cwl = 4;

    if(dxp * dyp > 0) cwp ^= 1;
    if(dxp < 0) cwp ^= 2;
    if(cwp == 0) cwp = 4;

    if(cwp != cwl)
}

int N,M,mod,wynik;
int a,b;
vector <pair<int,int> > kr;
vector <point > vec;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> mod;

    for(int i=0;i<N; ++i){
        cin >> a >> b;
        kr.push_back({a,b});
        vec.emplace_back(point(a,b,1));
    }
    for(int i=0; i<M; ++i){
        cin >> a >> b;
        vec.emplace_back(point(a,b,0));
    }

    for(auto e:kr){
        a = e.ff;
        b = e.ss;
        sort(vec.begin(),vec.end(),comp);
    }
}
/*
5 4 10
5 5
3 0
-1 -1
-3 4
1 10
1 0
-1 0
1 6
-2 5


*/