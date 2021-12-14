#include <bits/stdc++.h>

using namespace std;

int N;
int x;
int dw,pt;

int main(){
    cin >> N;
    for(int i=2; i<=N; ++i){
        x = i;
        while(x % 2 == 0){
            dw++;
            x /= 2;
        }
        while(x % 5 == 0){
            pt++;
            x /= 5;
        }
    }
    cout << min(dw,pt) << "\n";
}