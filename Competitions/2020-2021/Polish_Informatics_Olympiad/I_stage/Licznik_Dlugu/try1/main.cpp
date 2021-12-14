//Mateusz Wasilewski
//Licznik Dlugu
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,Q,a,b,wynik,now,was;
set <int> st;
const int half=131072;
int tree[half*2];
bool ok;
char test;
string W,Z;
vector <int> w (1,0);
vector <int> z (1,0);

void add(int x, int c){
    tree[x]+=c;
    if(x!=1){
        add(x/2,c);
    }
}
int sum(int x,int y){
    int res=0;
    while(x<=y){
        if(x%2){
            res+=tree[x];
            x++;
        }
        if(!(y%2)){
            res+=tree[y];
            y--;
        }
        x/=2;
        y/=2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    cin>>W;
    cin>>Z;
    for(int i=1; i<N; ++i){
        w.push_back(W[i-1]-48);
        z.push_back(Z[i-1]-48);
        if(w[i]+z[i]==9){
            add(half+i,1);
        }
        else if(w[i]+z[i]>9){
            st.insert(i);
        }
    }
    for(int i=0; i<Q; ++i){
        cin>>test;
        if(test=='S'){
            cin>>a;
            a = N-a;
            wynik = w[a] + z[a];
            auto poz=st.upper_bound(a);
            if(poz!=st.end()){
                if(*poz - a - 1==sum(half + a + 1, half + *poz - 1)){
                    wynik++;
                }
            }
            cout<<wynik%10<<"\n";
        }
        else{
            cin>>a>>b;
            a = N-a;
            was=w[a]+z[a];
            ok=0;
            if(test=='W'){
                if(w[a]!=b){
                    now=z[a]+b;
                    w[a]=b;
                    ok=1;
                }
            }
            else if(test=='Z'){
                if(z[a]!=b){
                    now=w[a]+b;
                    z[a]=b;
                    ok=1;
                }
            }
            if(ok){
                if(was>9 && now<=9)
                    st.erase(a);
                if(was==9)
                    add(half+a,-1);
                if(now>9)
                    st.insert(a);
                if(now==9)
                    add(half+a,1);
            }
        }
    }
    return 0;
}

/*
5 6
7341
0150
S 3
W 3 0
S 3
Z 1 9
S 1
S 3

5 5
7341
0150
S 5
S 4
S 3
S 2
S 1

*/