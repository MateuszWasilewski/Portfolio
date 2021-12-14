//Mateusz Wasilewski
//III LO w Gdyni
//XXVIII Olimpiada Informatyczna
#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
using namespace std;

ll wynik,a,N,l,k,d,np,u,p;
ll maxi;
set <int> st;
int tab[250007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> l >> k >> d;

    for(int i=0; i<N; ++i){
        cin >> a;
        st.insert(a);
        tab[i+1] = a;
    }
    for(int i=0; i<d; ++i){
        cin >> np >> u >> p;
        for(int z=0; z<np; ++z){
            cin >> a;
            st.insert(tab[a]);
        }
        for(int z=0; z<u; ++z){
            cin >> a;
            st.erase(tab[a]);
        }
        wynik = 0;
        maxi = 0;

        vector <pair<ll,int> > v;
        v.push_back({*st.begin(),1});
        v.push_back({l-*st.rbegin(),1});

        for(auto poz = st.begin(); poz!=st.end(); poz++){
            auto poz1 =poz;
            poz1++;
            if(poz1 != st.end()){
                v.push_back({*poz1 - *poz,2});
            }
        }
        auto poz = st.upper_bound(p);
        if(poz != st.begin()){
            auto poz1 = poz;
            poz1--;
            wynik += min(*poz - p, p- *poz1);
        }

        for(auto e:v){
            for(int z=1; z<= l; ++z){
                ll now = z * k;
                if(e.ss == 1){
                    wynik += min(e.ff, now) * 2;
                    maxi = max(maxi, min(e.ff, now));
                    if(e.ff <= now) break;
                }
                else{
                    if(now *2 >= e.ff){
                        wynik += e.ff;
                        wynik += 2* (now*2-e.ff);
                        maxi = max(maxi, (now*2-e.ff));
                        break;
                    }
                    else{
                        wynik += 2*now;
                        maxi = max(maxi, now);
                    }
                }
            }
        }
        cout << wynik - maxi << "\n";



        
    }

    return 0;
}
/*
3 5 2 1
2 3 5
0 1 3

2
*/