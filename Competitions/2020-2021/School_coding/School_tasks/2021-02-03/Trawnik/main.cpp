#include <bits/stdc++.h>

using namespace std;

int N,M,a;
vector <int> vn,vm;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    for(int i=0; i<N; ++i){
        cin >> a;
        vn.push_back(a);
    }
    for(int i=0; i<M; ++i){
        cin >> a;
        vm.push_back(a);
    }
    for(int i=0; i<N; ++i){
        for(int z=0; z<M; ++z){
            cout << min(vn[i], vm[z])<< " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
4 6
1 2 3 4
1 2 3 4 5 6

*/