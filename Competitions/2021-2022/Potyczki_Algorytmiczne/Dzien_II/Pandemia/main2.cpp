#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue < int> q_1, q_2;
    int n, t;
    string line;

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> t;
        cin >> line;

        int licz = 0, ile;
        int wynik = 0;
        for (int z = 0; z < t; z++) {
            if (line[z] == '0') {
                licz++;
            }
            else {
                if(licz) {
                    if (licz != z)
                        q_2.push(licz);
                    else
                        q_1.push(licz);
                }
                licz = 0;
                wynik++;
            }
        }
        if (licz > 0)
            q_1.push(licz);

        ile = 0;

        while (!q_1.empty() || !q_2.empty()) {
            int b = INT32_MIN, a = b, pow = 1;
            if (!q_1.empty())
                a = q_1.top();
            if (!q_2.empty())
                b = q_2.top();

            if (a == INT32_MIN || b == INT32_MIN) {
                if (a == INT32_MIN){
                    a = b;
                    pow = 2;
                    q_2.pop();
                }
                else   
                    q_1.pop();
            }
            else {
                if ((a - ile) * 2 >= b -2 * ile) { // a is bigger
                    q_1.pop();
                }
                else { 
                    a = b;
                    pow = 2;
                    q_2.pop();
                }
            }


            if (a - ile * pow > 0) {
                wynik += ile;
                if (pow == 2)
                    q_1.push(a - ile - 1);
                
                ile ++;
            }
            else {
                wynik += a;
            }
        }

        /*
        while (!q.empty()) {
            auto a = q.top();
            swap(a.first, a.second);
            a.second *= -1;
            q.pop();
            if (a.first <= ile * a.second)
                wynik += a.first;
            else {
                wynik += ile * a.second;
                a.first = min(a.first - ile * a.second , a.second);
                if (a.first == 2)
                    wynik ++;
                ile += a.first;
            }
        }*/
        cout << wynik << "\n";
    }
}