//Punkty Rankingowe
//Mateusz Wasilewski
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, a, b, c, mini=-1e13, suma;
vector <ll> pop (1,0);
vector <ll> out;
bool ok=1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin>>a;
        if(ok){
            b = a;
            c = a;
            pop.push_back(a);
            a = a/i;
            b = abs(b)-abs(a*i);
            if(b!=0) c = (c-a*i)/b;
            out.push_back(mini);
            suma = 0;
            for(int z=1; z<=i; ++z){
                if(z>b) out.push_back(a);
                else out.push_back(a+c);
                suma += out[out.size()-1];
                if(suma > pop[z]) ok = 0;
            }
            out.push_back(mini);
        }
    }
    if(ok){
        cout << "TAK\n" << out.size() << "\n";
        for(auto e:out){
            cout << e << " ";
        }
        cout << "\n";
    }
    else cout << "NIE\n";
    return 0;
}
/*
4
3 4 5 -1

10
3 1 4 1 5 9 2 6 5 3
*/