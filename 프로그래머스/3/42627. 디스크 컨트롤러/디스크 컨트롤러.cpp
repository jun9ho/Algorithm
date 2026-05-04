#include <bits/stdc++.h>

using namespace std;

using T = tuple<int,int,int>; // 소요시간, 요청시각, 작업번호

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size();

    priority_queue<T, vector<T>, greater<T>> pq;

    sort(jobs.begin(), jobs.end()); // 요청시각 기준 정렬

    int time = 0;
    int i = 0;

    while (i < n || !pq.empty()) {

        // 현재 시간까지 요청된 작업들을 pq에 넣기
        while (i < n && jobs[i][0] <= time) {
            pq.push({jobs[i][1], jobs[i][0], i});
            i++;
        }

        // 처리할 작업이 없으면 다음 작업 요청 시각으로 점프
        if (pq.empty()) {
            time = jobs[i][0];
            continue;
        }

        // 가장 소요시간 짧은 작업 처리
        auto [dur, req, idx] = pq.top();
        pq.pop();

        time += dur;
        answer += time - req;
    }

    return answer / n;
}