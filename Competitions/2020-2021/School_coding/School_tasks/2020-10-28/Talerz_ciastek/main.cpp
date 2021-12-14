#include <bits/stdc++.h>

using namespace std;

int N,M,wynik=2000,a,b;
vector <string> line;
string word;
int tab[1000];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>N>>M;
    for(int i=0; i^N; ++i){
        cin>>word;
        line.push_back(word);
        a=0;
        for(int z=0; z^M; ++z){
            tab[z]=a+1;
            if(word[z]=='#')
                a++;
            else
                a=0;
        }
        a=0;
        for(int z=M-1; z>=0; --z){
            tab[z]+=a;
            if(word[z]=='#'){
                a++;
                wynik=min(wynik,tab[z]);
            }
            else
                a=0;
        }
    }
    for(int z=0; z^M; ++z){
        a=0;
        for(int i=0; i^N; ++i){
            tab[i]=a+1;
            if(line[i][z]=='#')
                a++;
            else
                a=0;
        }
        a=0;
        for(int i=N-1; i>=0; --i){
            tab[i]+=a;
            if(line[i][z]=='#'){
                a++;
                wynik=min(wynik,tab[i]);
            }
            else
                a=0;
        }
    }
    if(wynik==2000){
        wynik=0;
    }
    cout<<wynik<<"\n";

    return 0;
}
/*
3 4
####
####
####

6 5
##...
###..
.####
.####
####.
###..

*/