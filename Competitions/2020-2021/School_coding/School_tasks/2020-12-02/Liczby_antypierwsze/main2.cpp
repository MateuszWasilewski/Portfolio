#include <bits/stdc++.h>

using namespace std;
int N,wynik;
vector <int> v;
int main(){
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(12);
    v.push_back(24);
    v.push_back(36);
    v.push_back(48);
    v.push_back(60);
    v.push_back(120);
    v.push_back(180);
    v.push_back(240);
    v.push_back(360);
    v.push_back(720);
    v.push_back(840);
    v.push_back(1260);
    v.push_back(1680);
    v.push_back(2520);
    v.push_back(5040);
    v.push_back(7560);
    v.push_back(10080);
    v.push_back(15120);
    v.push_back(20160);
    v.push_back(25200);
    v.push_back(27720);
    v.push_back(45360);
    v.push_back(50400);
    v.push_back(55440);
    v.push_back(83160);
    v.push_back(110880);
    v.push_back(166320);
    v.push_back(221760);
    v.push_back(277200);
    v.push_back(332640);
    v.push_back(498960);
    v.push_back(554400);
    v.push_back(665280);
    v.push_back(720720);
    v.push_back(1081080);
    v.push_back(1441440);
    v.push_back(2162160);
    v.push_back(2882880);
    v.push_back(3603600);
    v.push_back(4324320);
    v.push_back(6486480);
    v.push_back(7207200);
    v.push_back(8648640);
    v.push_back(10810800);
    v.push_back(14414400);
    v.push_back(17297280);
    v.push_back(21621600);
    v.push_back(32432400);
    v.push_back(36756720);
    v.push_back(43243200);
    v.push_back(61261200);
    v.push_back(73513440);
    v.push_back(110270160);
    v.push_back(122522400);
    v.push_back(147026880);
    v.push_back(183783600);


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(auto e:v){
        if(e<=N) wynik = e;
        else break;
    }
    cout << wynik << "\n";
}