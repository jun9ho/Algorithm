#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    //1 3 5 7
    //2 2 6 8

    //4 2 2 1
    int cnt = 0;
    int idx = 0;

    for(int i = 0; i < A.size(); i++){
        while(idx < B.size() && B[idx] <= A[i]){
            idx++;
        }
        if (idx >= B.size()) return cnt;
        cnt++;
        idx++;
    }
    return cnt;
}