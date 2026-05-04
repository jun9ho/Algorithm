#include <bits/stdc++.h>
using namespace std;
int solution(string s)
{
    int answer = 1;
    int len = s.size();
    for(int i=0;i<len;i++){
        int size = 1;
        int left = i-1;
        int right = i+1;
        while(left>=0 && right<len){
            if(s[left]==s[right]){
                size+=2;
                answer=max(size,answer);
            }
            else break;
                
            left--;
            right++;
        }
    }
    
    for(int i=0;i<len;i++){
        int size = 0;
        int left = i;
        int right = i+1;
        while(left>=0 && right<len){
            if(s[left]==s[right]){
                size+=2;
                answer=max(size,answer);
            }
            else break;
                
            left--;
            right++;
        }
    }

    return answer;
}