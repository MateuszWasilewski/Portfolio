#include <bits/stdc++.h>

using namespace std;

int N,a,b;
int p,k;
const int half = 131072;
int tree[half*2];

int ask(int x){
    x += half;
    int ans = 0;
    while(true){
        ans += tree[x];
        if(x == 1) return ans;
        x/=2;
    }
    return ans;
}
int add(int x,int y, int c){
    x += half;
    y += half;
    while(x <= y){
        if(x%2){
            tree[x] += c;
            x++;
        }
        if(!(y%2)){
            tree[y] += c;
            y--;
        }
        x/=2;
        y/=2;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0; i < N; ++i){
        cin >> a >> b;
        p = ask(a);
        k = ask(b);
        cout << p + k << "\n";
        tree[a + half] -= p;
        tree[b + half] -= k;
        add(a+1,b-1,1);
    }
}