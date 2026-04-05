#include <bits/stdc++.h>
using namespace std;



void dfs(int idx, int n, int m,vector<int> v,vector<bool>visit) {
    
    if (idx == m) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visit[i]) continue;
        visit[i] = true;
        v.push_back(i);
        dfs(idx + 1, n, m, v, visit);
        v.pop_back();
        visit[i] = false;
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<bool> visit(n+1, false);
    dfs(0,n, m,{},visit);
}