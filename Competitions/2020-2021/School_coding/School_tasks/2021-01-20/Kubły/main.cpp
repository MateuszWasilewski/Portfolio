#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

const int half = 131072;
int N, M, a, wynik;
vector <pair<int,int> > st;
int poz[100001];

struct tre{
    int mini = 0;
    int add = 0;
};
tre tree[half*2];

void actual(int x){
    while(true){
        tree[x].mini = tree[x].add;
        if(x < half) tree[x].mini += min(tree[x*2].mini,tree[x*2+1].mini);
        if(x==1) return;
        x/=2;
    }
}

void add(int x,int y, int c){
    x += half;
    y += half;
    while(x <= y){
        if(x%2){
            tree[x].add += c;
            actual(x);
            x++;
        }
        if(!(y%2)){
            tree[y].add += c;
            actual(y);
            y--;
        }
        x/=2;
        y/=2;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;

    for(int i=0; i<N; ++i){
        cin >> a;
        st.push_back({a,-i});
    }
    sort(st.begin(), st.end());
    for(int i=0; i<st.size(); ++i){
        poz[-st[i].ss] = i; 
    }

    for(int k=0; k<N/2; ++k){
        add(poz[k], half-1, 1);
        add(poz[k*2+1], half-1, -1);
        if(k>0){
            add(poz[k], half-1, 1);
            add(poz[k*2], half-1, -1);
        }
        if(tree[1].mini>=0) wynik = k+1;
    }
    cout << wynik << "\n";

    return 0;
}
/*
5 10
2 2 1 4 3 2 5 4 2 3

5 8
2 2 1 4 3 2 5 4

*/