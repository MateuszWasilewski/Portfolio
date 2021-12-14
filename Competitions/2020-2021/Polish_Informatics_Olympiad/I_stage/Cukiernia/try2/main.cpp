#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
using namespace std;

int N,k,wh;
ll a,b,c;
ll suma[3];
ll sum;
ll wynik=LLONG_MAX;
struct obj{
    int a,b,c;
};
vector <ll> best;
vector <pair<ll, int> > v[3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0; i^N; ++i){
        cin>>a>>b>>c;
        suma[0]+=a;
        suma[1]+=b;
        suma[2]+=c;
        v[0].push_back({b+c,i});
        v[1].push_back({a+c,i});
        v[2].push_back({a+b,i});
        best.push_back(min(a+b,min(b+c,a+c)));
    }
    for(int i=0;i<3;++i){
        sort(v[i].begin(),v[i].end());
        if(suma[i]>0){
            k++;
        }
        else{
            wh=i;
        }
    }
    
    /*cout<<"\n";
    for(int i=0;i<3;++i){
        for(int z=0;z<3;++z){
            cout<<v[z][i].ff<<","<<v[z][i].ss<<" ";
        }
        cout<<"\n";
    }*/
    if(k==3){
        obj ob;
        for(int i=0; i<3; ++i){
            for(int z=0; z<3; ++z){
                for(int j=0; j<3; ++j){
                    if(!(v[0][i].ss==v[1][z].ss || v[1][z].ss==v[2][j].ss || v[0][i].ss == v[2][j].ss)){
                        sum=v[0][i].ff + v[1][z].ff + v[2][j].ff;
                        if(sum<wynik){
                            wynik=min(wynik,sum);
                            ob.a=v[0][i].ss;
                            ob.b=v[1][z].ss;
                            ob.c=v[2][j].ss;
                        }
                    }
                }
            }
        }
        best[ob.a]=0;
        best[ob.b]=0;
        best[ob.c]=0;
        for(int i=0; i^N; ++i){
            wynik+=best[i];
        }
        cout<<wynik<<"\n";
    }
    else if(k==2){
        if(wh==0){
            obj ob;
            for(int z=0; z<3; ++z){
                for(int j=0; j<3; ++j){
                    if(!(v[1][z].ss==v[2][j].ss)){
                        sum=v[1][z].ff + v[2][j].ff;
                        if(sum<wynik){
                            wynik=min(wynik,sum);
                            ob.b=v[1][z].ss;
                            ob.c=v[2][j].ss;
                        }
                    }
                }
            }
            best[ob.b]=0;
            best[ob.c]=0;
            for(int i=0; i^N; ++i){
                wynik+=best[i];
            }
            cout<<wynik<<"\n";
        }
        else if(wh==1){
            obj ob;
            for(int i=0; i<3; ++i){
                for(int j=0; j<3; ++j){
                    if(!(v[0][i].ss == v[2][j].ss)){
                        sum=v[0][i].ff + v[2][j].ff;
                        if(sum<wynik){
                            wynik=min(wynik,sum);
                            ob.a=v[0][i].ss;
                            ob.c=v[2][j].ss;
                        }
                    }
                }
            }
            best[ob.a]=0;
            best[ob.c]=0;
            for(int i=0; i^N; ++i){
                wynik+=best[i];
            }
            cout<<wynik<<"\n";
        }
        else{
            obj ob;
            for(int i=0; i<3; ++i){
                for(int z=0; z<3; ++z){
                    if(!(v[0][i].ss==v[1][z].ss)){
                        sum=v[0][i].ff + v[1][z].ff;
                        if(sum<wynik){
                            wynik=min(wynik,sum);
                            ob.a=v[0][i].ss;
                            ob.b=v[1][z].ss;
                        }
                    }
                }
            }
            best[ob.a]=0;
            best[ob.b]=0;
            for(int i=0; i^N; ++i){
                wynik+=best[i];
            }
            cout<<wynik<<"\n";
        }
    }
    else{
        cout<<"0\n";
    }

}

/*
5
5 1 1
0 3 4
1 4 3
4 0 0
0 0 0

*/