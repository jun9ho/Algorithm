#include <bits/stdc++.h>
using namespace std;


int solution(int n, vector<int> tops) {
    int MOD = 10007;
    vector<int> v(n);
    v[0] = tops[0]+3;
    v[1] = (tops[1]+3)*v[0]-1;
    
    //4 15 41 164-14
    for(int i=2;i<n;i++){
        v[i] = (tops[i]+3)*v[i-1] - v[i-2];
        v[i] %= MOD;
    }
    while(v[n-1]<0){
        v[n-1]+=MOD;
    }
    return v[n-1];
}
