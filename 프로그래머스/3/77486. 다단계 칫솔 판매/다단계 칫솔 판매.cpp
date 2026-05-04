#include <bits/stdc++.h>

using namespace std;

struct Node{
    Node * parent;
    int idx;
    int money = 0;
};


void what(int idx,int money, vector<Node>& v){
    
    if(money==0){
        return;
    }
    if(idx==0){
        v[idx].money+=money;
        return;
    }

    int curmoney = money/10;
    v[idx].money+= (money-curmoney);
    what(v[idx].parent->idx,curmoney,v);
    return;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    //노드를 만들고, leafnode에서 위로 올라가는 구조, 자기의 이익금을 얻고 나머지 위에 주는구조
    //enroll 은 center를제외한 명단
    //referral은 부모노드 이름
    map<string,int> m;
    m["-"]=0;
    for(int i=0;i<enroll.size();i++){
        m[enroll[i]]= i+1;//center(-)->0 john -> 1 mary -> 2
    }
    //john -> 0
    vector<Node> v(enroll.size()+1);
    v[0].idx=0;
    v[0].money=0;
    for(int i=0;i<referral.size();i++){
        v[i+1].parent = &v[m[referral[i]]];
        v[i+1].idx=i+1;
        v[i+1].money=0;
    }
    
    //Node 계산을해서
    for(int i=0;i<seller.size();i++){
        int idx = m[seller[i]];
        int money = amount[i]*100;
        
        what(idx,money,v);
        
    }
    for(int i=1;i<v.size();i++){
        answer.push_back(v[i].money);
    }
    
    return answer;
}