#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int N,k,t,a,wynik;
vector <int> vec;
deque <pair<int,int> > dq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> a;
        vec.push_back(a);
    }
    cin >> t;
    for(int i=0; i<t; ++i){
        cin >> k;
        dq.clear();
        dq.push_back({0,0});
        for(int z=1; z<N; ++z){
            while(dq.front().ss + k < z){
                dq.pop_front();
            }
            wynik = dq.front().ff;
            if(vec[dq.front().ss] <= vec[z]) wynik++;

            while(!dq.empty()){
                if(dq.back().ff > wynik || (dq.back().ff == wynik && vec[dq.back().ss] <= vec[z])) dq.pop_back();
                else break;
            }
            dq.push_back({wynik,z});
        }
        cout << wynik << "\n";

    }
}
/*
9
4 6 3 6 3 7 2 6 5
2
2
5


*/