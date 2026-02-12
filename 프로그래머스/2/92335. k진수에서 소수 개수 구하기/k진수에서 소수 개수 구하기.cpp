#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long a){
    if(a==1) return false;
    if(a==2||a==3) return true;
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    //k진수로 바꾸고
    //0으로 파싱하고
    //이거가 소수인지아닌지 판단하는
    //소수개수 구하기
    string s = "";
    while(n>0){
        int a = n / k;
        int b = n % k;
        s += to_string(b);
        n = a;
    }
    reverse(s.begin(),s.end());
    stringstream ss(s);
    string token;
    while(getline(ss,token,'0')){
        if(token.length()==0) continue;
        if(isPrime(stol(token))) answer++;
    }
    
    
    return answer;
}