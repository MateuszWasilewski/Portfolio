#include <bits/stdc++.h>
#define ld long double
using namespace std;

int t;
char test;
ld a,b,c;
ld wynik = 1;
ld PI = 3.14159265;

int main(){
    cin >> t;
    for(int i=0; i<t; ++i){
        cin >> test >> a >> b >> c;
        if(test == 'H'){
            ld p = (a + b + c)/2;
            wynik = p * (p-a) * (p-b) * (p-c);
            wynik = sqrt(wynik);
        }
        else if(test == 'S'){
            wynik = a * b * sin(c*PI/180) / 2;
        }
        else{
            wynik = a * a;
            a = 180 - b - c;
            wynik = wynik * sin(b*PI/180) * sin(c*PI/180) / sin(a*PI/180) / 2;
        }
        cout << fixed << setprecision(2) << wynik << "\n";
    }

}