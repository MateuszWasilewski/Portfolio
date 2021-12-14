#include <bits/stdc++.h>
#define ll long long
using namespace std;

deque <int> dq;
ll N;
int main(){
    cin >> N;
    while(N){
        dq.push_front((N%5)*2);
        N/=5;
    }
    while(!dq.empty()){
        cout << dq.front();
        dq.pop_front();
    }
    cout << "\n";
}