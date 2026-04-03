#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int didx = n-1;
    int pidx = n-1;
    
    while(1){
        
        int curcap = cap;
        int curcap2 = cap;
        
        int maxd = -1;
        int maxp = -1;

        for(int i= didx; i>=0;i--){
            if(deliveries[i]==0) continue;
            maxd = max(maxd,i);
            if(curcap>=deliveries[i]){
                curcap -= deliveries[i];
                deliveries[i]=0;
                if(curcap==0||i==0){
                    didx=i-1;
                    break;
                }
            }
            else{
                deliveries[i] -= curcap;
                curcap=0;
                didx=i;
                break;
            }
        }
        
        for(int i= pidx; i>=0;i--){
            if(pickups[i]==0) continue;
            maxp = max(maxp,i);
            if(curcap2>=pickups[i]){
                curcap2 -= pickups[i];
                pickups[i]=0;
                if(curcap2==0||i==0){
                    pidx=i-1;
                    break;
                }
            }
            else{
                pickups[i] -= curcap2;
                curcap2=0;
                pidx=i;
                break;
            }
        }
        if(maxp==-1 && maxd==-1) break;
        answer+=(2*(max(maxp+1,maxd+1)));
    }
    
    return answer;
}