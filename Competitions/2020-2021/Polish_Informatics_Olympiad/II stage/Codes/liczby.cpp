#include <bits/stdc++.h>

using namespace std;


//NWD

int NWD(int a, int b){
    int c;
    while(a != 0){
        c = a;
        a = b % a;
        b = c;
    }
    return b;
}

//NWW

int NWW(int a,int b){
    return a*b/NWD(a,b);
}

//liniowy algorytm euklidesa
int main(){

    const int size = 1000000;
    vector <int> prime;
    bool notprime[size];
    for(int i=2; i<size; ++i){
        if(!notprime[i]) prime.push_back(i);
        for(auto e:prime){
            if(e*i < size) notprime[e*i] = 1;
            else break;
        }
    }

//rozklad na liczby pierwsze
    int N = 100000;
    int sqt = sqrt(N);
    int k=2;
    while(k <= sqt){
        while(N % k == 0){
            N /= k;
            //pierwsze k dzieli N
        }
        k++;
    }
    if(N != 1){
        // N jest pierwsze i dzieli początkowe N
    }

}

