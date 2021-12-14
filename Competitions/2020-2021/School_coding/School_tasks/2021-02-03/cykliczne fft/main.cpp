#include <bits/stdc++.h>

using namespace std;

struct obj{
public:
    int a=0;
    int ans=0;
};

int N,a,b;
vector <obj> vec;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    obj ob1;
    for(int i=0; i<N; ++i){
        cin >> a;
        ob1.a = a;
        vec.emplace_back(ob1);
    }
    for(int i=0; i<N; ++i){
        cin >> a;
        for(int z=0; z<N; ++z){
            b = (i+z) % N;
            vec[b].ans = max(vec[b].ans, vec[z].a + a); 
        }
    }
    for(int i=0; i<N; ++i){
        cout << vec[i].ans << " ";
    }
    cout << "\n";
    return 0;
}
/*
8
7 5 1 4 6 3 2 0
1 4 6 7 0 3 2 5
*/