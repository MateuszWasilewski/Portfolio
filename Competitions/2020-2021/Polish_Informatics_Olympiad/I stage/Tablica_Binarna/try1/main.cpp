//Tablica Binarna
//Mateusz Wasilewski
#include <bits/stdc++.h>

using namespace std;
int N,M,Q,wynik;
bitset<1001>bt[1001];

void change(int x, int y){
    if(bt[x][y]){
        bt[x][y]=0;
        if(x>0 && y>0)
            wynik--;
    }
    else{
        bt[x][y]=1;
        if(x>0 && y>0)
            wynik++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>Q;
    int x,x2,y,y2;
    for(int i=0; i^Q; ++i){
        cin>>x>>y>>x2>>y2;
        change(x2,y2);
        change(x-1,y2);
        change(x2,y-1);
        change(x-1,y-1);
        cout<<wynik<<"\n";
    }
    return 0;
}
/*
2 3 3
1 2 2 2
1 1 2 1
1 2 1 3

*/