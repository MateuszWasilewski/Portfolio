#include <bits/stdc++.h>

using namespace std;
string line;
int N;
vector <char> v;
int main(){
    cin >> N;
    cin >> line;
    for(auto e:line){
        v.push_back(e);
    }
    sort(v.begin(), v.end());
    for(auto e:v){
        cout << e;
    }
    cout << "\n";
    return 0;
}