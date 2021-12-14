#include <bits/stdc++.h>
#define sz 1010

using namespace std;

int N,a,maxi=-1;
bitset <sz> bt;
bitset <sz> change;

vector <int> vec,pot;

void odejmij(int x){
    if(bt[x]){
        bt[x] = 0;
    }
    else{
        odejmij(x+1);
        bt[x] = 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> a;
        if(a == 1){
            change[i] = 1;
            maxi = i;
        }
    }
    for(int i = 0; i <= maxi; ++i){
        bt[i] = 1;
    }
    for(int i = maxi-1; i>=0; --i){
        if(change[i]){
            for(int z=0; z<=i; ++z){
                odejmij(z);
            }
        }
    }
    
    vec.push_back(0);
    pot.push_back(1);
    for(int i=0; i<= maxi; ++i){
        if(bt[i]){
            while(vec.size() < pot.size()){
                vec.push_back(0);
            }
            for(int z=0; z<pot.size(); ++z){
                vec[z] += pot[z];
                if(vec[z] > 9){
                    if(z+1 == vec.size()) vec.push_back(0);
                    vec[z+1] += vec[z]/10;
                    vec[z] %= 10;
                }
            }
        }
        for(int z=0; z<pot.size(); ++z){
            pot[z]*=2;
        }
        for(int z=0; z<pot.size(); ++z){
            if(pot[z] > 9){
                if(z+1 == pot.size()) vec.push_back(0);
                pot[z+1] += pot[z]/10;
                pot[z] %= 10;
            }
        }
    }
    for(int i=vec.size()-1; i>=0; --i){
        cout << vec[i];
    }

    cout << "\n";
}   

/*
4
1 0 1 0

*/