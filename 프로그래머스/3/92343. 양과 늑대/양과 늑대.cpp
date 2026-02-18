#include <bits/stdc++.h>

using namespace std;

int answer = 0;

void bfs(int num, int sheep, int wolves,unordered_map<int, vector<int>> graph,vector<int> info, vector<bool> candidates) {
    int size = candidates.size();
    if (info[num]) wolves += 1;
    else sheep += 1;
    if (0 < sheep && sheep <= wolves) return;
    
    answer = max(answer, sheep);
    
    for (const auto& ele : graph[num]){
        candidates[ele] = true;
    }
    //1,2 = true
    for (int i = 0; i < size; ++i){
        if (candidates[i]){
            candidates[i] = false;
            bfs(i, sheep, wolves,graph,info,candidates);
            candidates[i] = true;
        }
    }

}

int solution(vector<int> info, vector<vector<int>> edges) {

    int size = info.size();
    vector<bool> candidates(size, false);
    unordered_map<int, vector<int>> graph;
    for (const auto& ele : edges)
    {
        graph[ele[0]].push_back(ele[1]);
    }

    bfs(0, 0, 0,graph,info,candidates);

    return answer;
}