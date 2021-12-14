#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, a, score;
    vector <int> v;
    priority_queue <int> q1, q2;
    cin >> N;
    int p, k, wynik = 0, licz = 0;

    for(int i = 0; i < N; i++) {
        cin >> a;
        if(a == N)
            p = i;
        v.push_back(a);
    }

    for (int i = 0; i < N; i++) {
        while (!q1.empty())
            q1.pop();
        while (!q2.empty())
            q2.pop();
        
        for (int z = i; z < N; z++) {
            a = v[z];
            if (q2.empty() || a > -q2.top()){
                q2.push(-v[z]);

                if (q2.size() > q1.size() + 1) {
                    a = q2.top();
                    q2.pop();
                    q1.push(-a);
                }
            }
            else {
                q1.push(v[z]);
                
                if (q1.size() > q2.size()) {
                    a = q1.top();
                    q1.pop();
                    q2.push(-a);
                }
            }

            score = q1.size() + q2.size();
            if (q1.size() == q2.size())
                score += q1.top() - q2.top();
            else
                score += 2 * -q2.top();
            
            if (score > wynik){
                wynik = score;
                licz = 0;
            }
            if (score == wynik)
                licz++;
        }
    }
    cout << wynik << " " << licz << "\n";

}