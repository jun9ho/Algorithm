#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, long long> parent;
long long Find(long long x) {
    auto iter = parent.find(x);
    if(iter==parent.end()){
        parent[x] = x+1;
        return x;
    }
    parent[x] = Find(parent[x]);
    return parent[x];
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for (auto want : room_number) {
        long long assigned = Find(want);
        answer.push_back(assigned);
    }
    return answer;
}
