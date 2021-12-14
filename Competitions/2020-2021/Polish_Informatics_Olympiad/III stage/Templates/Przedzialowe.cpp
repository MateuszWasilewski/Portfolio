#include <bits/stdc++.h>

using namespace std;

const int half=8;
int tree[half*2];

//Iteracyjne
void add(int x,int y, int c){
    while(x <= y){
        if(x%2){
            tree[x] += c;
            x++;
        }
        if(!(y%2)){
            tree[y] += c;
            y--;
        }
        x/=2;
        y/=2;
    }
}
int suma(int x){
    int wynik = 0;
    while(x>0){
        wynik += tree[x];
        x/=2;
    }
    return wynik;
}

//rekurencyjne
void rek(int x, int a, int b, int l, int p){
    if(a<=l && p<=b){
        //jestem w przedziale
        return;
    }

    //ew push down

    int mid = (l+p)/2;
    if(a <= mid)
        rek(x*2, a, b, l, mid);
    if(mid <= b)
        rek(x*2+1,a, b, mid+1, p);

    return;
}


//drzewo Fenwicka
int Fenwick[half+1];

int lsb(int x){
    return x & -x;
}

void add(int x, int c){
    while(x <= half){
        Fenwick[x] += c; //lub dowolna odwracalna operacja
        x = x + lsb(x);
    }
    return;
}

int ask(int x){
    int wynik = 0;
    while(x > 0){
        wynik += Fenwick[x];
        x = x - lsb(x);
    }
    return wynik;
}

int ask_span(int x, int y){
    return (ask(y) - ask(x-1));
}