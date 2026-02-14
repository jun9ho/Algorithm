#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> food_times, long long k) {
    long long answer = 0;
    long long size = food_times.size();
    map<long long,long long> m;// 숫자, 개수
    for(int i=0;i<food_times.size();i++){
        m[food_times[i]]++;
    }
    long long t;
    long long c = 0;
    for(auto iter=m.begin();iter!=m.end();iter++){
        t = ((iter->first)-c) * size; // 총 t초만큼 흐름
        if(t>k){
            k %= size;
            for(int i=0;i<food_times.size();i++){
                if(food_times[i]<=c) continue;
                if(k==0) return (i+1);
                k--;
            }
        }
        else{
            c = iter->first; 
            k -= t;
            size -= iter->second;
        }
    }
    
    
    return -1;
}