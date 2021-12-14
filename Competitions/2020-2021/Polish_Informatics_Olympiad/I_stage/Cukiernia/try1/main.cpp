//Cukiernia
//Mateusz Wasilewski

#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
using namespace std;
class obj{
public:
    ll d=0,p=0,r=0;
};
pair<obj,int> tab[3][3];
int N;
obj total;
ll suma,a,b,c,now;

void puttab(obj work, int poz){
    for(int i=0;i<3;++i){
        if(work.p+work.r<tab[0][i].ff.p+tab[0][i].ff.r){
            for(int z=2;z>i;++z){
                swap(tab[0][z],tab[0][z-1]);
            }
            tab[0][i]={work,poz};
            break;
        }
    }
    for(int i=0;i<3;++i){
        if(work.d+work.r<tab[1][i].ff.d+tab[1][i].ff.r){
            for(int z=2;z>i;++z){
                swap(tab[1][z],tab[1][z-1]);
            }
            tab[1][i]={work,poz};
            break;
        }
    }
    for(int i=0;i<3;++i){
        if(work.p+work.d<tab[2][i].ff.p+tab[2][i].ff.d){
            for(int z=2;z>i;++z){
                swap(tab[2][z],tab[2][z-1]);
            }
            tab[2][i]={work,poz};
            break;
        }
    }
}

void godown(){
    bool ok;
    ll sum;
    ll corr=LLONG_MAX;
    for(int i=0; i<3; ++i){
        for(int z=0; z<3; ++z){
            for(int j=0; j<3; ++j){
                ok=1;
                if(total.d>0 && total.p>0){
                    if(tab[0][i].ss==tab[1][z].ss){
                        ok=0;
                    }
                }
                if(total.d>0 && total.r>0){
                    if(tab[0][i].ss==tab[2][j].ss){
                        ok=0;
                    }
                }
                if(total.r>0 && total.p>0){
                    if(tab[2][j].ss==tab[1][z].ss){
                        ok=0;
                    }
                }
                if(ok){
                    
                    corr=min(corr,)
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    obj work;
    work.p=LLONG_MAX;
    work.d=LLONG_MAX;
    work.r=LLONG_MAX;

    for(int i=0;i<3;++i){
        for(int z=0;z<3;++z){
            tab[i][z]={work,-1};
        }
    }
    for(int i=0; i<N; ++i){
        cin>>a>>b>>c;
        total.d+=a;
        total.p+=b;
        total.r+=c;
        work.d=a;
        work.p=b;
        work.r=c;
        suma+=min(b+c,min(a+c,a+b));
        puttab(work,i);
    }



    return 0;
}