#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int prze = 100002;
const int limit = 400007;
ll odp[limit][3];
ll wynik;
int x1,x2,y,y2,N,t,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> x1 >> y >> x2 >> y2;
        //pionowe
        odp[x1+prze][0] += (y2-y);
        odp[x1+prze+1][0] -= (y2-y);
        odp[x2+prze+1][0] -= (y2-y);
        odp[x2+prze+2][0] += (y2-y);
        //na skos w lewo
        if(prze+x1+y+1 < limit) odp[prze+x1+y+1][1] += 1;
        if(prze+x1+y2+1 < limit) odp[prze+x1+y2+1][1] -= 1;
        if(prze+x2+y+1 < limit) odp[prze+x2+y+1][1] -= 1;
        if(prze+x2+y2+1 < limit) odp[prze+x2+y2+1][1] += 1;
        //na skos w prawo
        odp[prze+x1-y2+1][2] += 1;
        odp[prze+x1-y+1][2] -= 1;
        odp[prze+x2-y2+1][2] -= 1;
        odp[prze+x2-y+1][2] += 1;
    }
    for(int z=0; z<3; ++z){
        c = 0;
        for(int i=1; i<limit; ++i){
            c += odp[i][z];
            odp[i][z] = odp[i-1][z] + c;
        }
    }
    
    cin >> t;
    for(int i=0; i<t; ++i){
        cin >> a >> b;
        wynik = odp[a+prze][b-1];
        wynik *= wynik;
        if(b>1) wynik *= 2;
        cout << wynik << "\n";
    }
    return 0;
}

/*
5
1 4 3 6
7 4 9 6
4 3 6 7
1 8 3 10
7 8 10 10
9
11 1
8 1
-7 1
-4 1
-1 1
14 1
17 1
2 1
5 1

4
1 1 4 3
2 4 5 7
6 3 10 5
8 1 9 2
2
0 3
9 1

*/