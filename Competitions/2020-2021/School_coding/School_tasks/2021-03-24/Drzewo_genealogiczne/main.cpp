#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

struct node{
    int id;
    int left = 0;
    int right = 0;
    int depth;
};

int N,a,b;
int wynik;
unordered_map <int, node> mapa;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> a;
    node ob1;
    ob1.id = a;
    ob1.depth = 0;
    mapa[a] = ob1;
    for(int i=1; i<N; ++i){
        auto poz = mapa.find(a);
        cin >> b;
        while(true){
            if(b == poz->ss.id){
                wynik = max(wynik, poz->ss.depth);
                break;
            }
            else if(b < poz->ss.id){
                if(poz->ss.left == 0){
                    poz->ss.left = b;
                    node ob;
                    ob.id = b;
                    ob.depth = poz->ss.depth+1;
                    mapa[b] = ob;
                }
                poz = mapa.find(mapa[poz->ss.left].id);
            }
            else{
                if(poz->ss.right == 0){
                    poz->ss.right = b;
                    node ob;
                    ob.id = b;
                    ob.depth = poz->ss.depth+1;
                    mapa[b] = ob;
                }
                poz = mapa.find(mapa[poz->ss.right].id);
            }
        }
    }
    cout << wynik << "\n";
    return 0;
}

/*
3
2 3 1

7
5 7 1 4 2155 2 3

*/