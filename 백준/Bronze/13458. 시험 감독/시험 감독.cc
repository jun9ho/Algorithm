#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, a, b, c;
    vector<long long> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    cin >> b >> c;
    long long total = 0;
    total = n;
    for (long long i = 0; i < n; i++) {
        if (v[i] - b <= 0) continue;
        else {
            if (((v[i] - b) % c) == 0){
                total += ((v[i] - b) / c);
            }
            else {
                total += (((v[i] - b) / c) + 1);
            }
        }
    }

    cout << total;
    return 0;


}