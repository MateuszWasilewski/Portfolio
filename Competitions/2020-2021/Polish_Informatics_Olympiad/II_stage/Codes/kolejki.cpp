#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;


//monotoniczna rosnąca z limitem
class mtque{
    deque <pair<int,int> > dq;

    void add(pair<int,int> a){
        while(!dq.empty()){
            if(dq.back().ff >= a.ff){
                dq.pop_back();
            }
            else break;
        }
        dq.push_back(a);
    }
    pair<int,int> front(int limit){
        while(dq.front().ss < limit) dq.pop_front();
        return dq.front();
    }
};
//priorytetowa rosnąca
//w miejsce pair<int,int> wstawić co trzeba
priority_queue <pair<int,int>, vector <pair<int,int> >, greater<pair<int,int> >  > q;