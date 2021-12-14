//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

int N;
ll a,b,c,d;
vector <ll> prv;
vector <ll> now;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> d;
    cin >> c;
    for(int z=0; z<c; ++z){
        cin >> a;   
        prv.push_back(a);
    }
    for(int i=1; i<N; ++i){
        cin >> c;
        ll wynik = INT64_MAX;
        now.clear();
        for(int z=0; z<c; ++z){
            cin >> b;   
            now.push_back(b);
        }
        
        

        if(now.size() * prv.size()>250000){
            ll prvsuma, nowsuma;
            for(int z=0; now.size() - z >= prv.size(); ++z){
                ll work;
                work += abs(prv[0]-now[z])*prv.size();
                if(z>0){
                    work += (now[0] + now[z-1]) * z / 2;
                }
                if(now.size() - z > prv.size()){
                    work += (now[prv.size()+z] + now[now.size()-1])*(now.size()-prv.size()-z)/2;
                }
            }
            for(int z=0; prv.size() - z >= now.size(); ++z){
                ll work;
                work += abs(now[0]-prv[z])*now.size();
                if(z>0){
                    work += (prv[0] + prv[z-1]) * z / 2;
                }
                if(prv.size() - z > now.size()){
                    work += (prv[now.size()+z] + prv[prv.size()-1])*(prv.size()-now.size()-z)/2;
                }
            }


        }
        else{
            int pocz = 0;
            for(int z=0; z<=now.size(); ++z){
                for(int j=pocz; j<=prv.size(); ++j){
                    ll work = 0;
                    for(int k=0; k < z; ++k){
                        work += now[k];
                    }
                    for(int k=0; k < j; ++k){
                        work += prv[k];
                    }
                    int end=0;
                    for(int k = 0; z+k < now.size() && j + k < prv.size(); k++){
                        work += abs(now[z+k] - prv[j+k]);
                        end++;
                    }
                    for(int k=end+z; k<now.size(); k++){
                        work += (d-now[k]);
                    }
                    for(int k=end+j; k<prv.size(); k++){
                        work += (d-prv[k]);
                    }

                    if(wynik > work){
                        wynik = work;
                        pocz = j;
                    }
                    else break;

                }
            }
        }
        
        cout << wynik << "\n";
        prv = now;
    }
    return 0;
}
/*

3 10
2 4 7
3 3 6 8
1 5

3 11
0
0
10 1 2 3 4 5 6 7 8 9 10
*/