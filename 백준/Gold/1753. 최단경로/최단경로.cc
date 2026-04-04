#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    int K;
    cin >> K;

    vector<vector<pair<int, int>>> graph(V + 1);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
    }

    vector<int> dist(V + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[K] = 0;
    pq.push({ 0, K });

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < curDist) continue;

        for (auto& next : graph[cur]) {
            int nxt = next.first;
            int cost = next.second;

            if (dist[nxt] > curDist + cost) {
                dist[nxt] = curDist + cost;
                pq.push({ dist[nxt], nxt });
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}