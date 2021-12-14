#include <iostream>

using namespace std;
int N;
int a, b;
bool way;
int main(){
    cin >> N;
    a = 1;
    b = 2;
    N -= 2;
    way = 1;
    while(N){
        if(way) a += b;
        else b += a;
        way ^=1;
        N--;
    }
    if(way) a = b;
    cout << a << "\n";
    return 0; 
}