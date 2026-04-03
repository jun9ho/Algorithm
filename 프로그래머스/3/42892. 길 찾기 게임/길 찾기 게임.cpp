#include <bits/stdc++.h>

using namespace std;

struct Node{
    int idx;
    int x;
    int y;
    Node* leftNode = nullptr;
    Node* rightNode = nullptr;
};

bool comp(Node a, Node b){
    if(a.y==b.y){
        return a.x<b.x;
    }
    return a.y>b.y;
}

void createGraph(Node& a,Node& parent){
    
    int ax = a.x;
    int ay = a.y;
    int px = parent.x;
    int py = parent.y;
    if(ay>=py) return;
    if(ax<px){
        if(parent.leftNode==nullptr){
            parent.leftNode = &a;
        }
        else{
            createGraph(a, *parent.leftNode);
        }
        
    }
    else if(ax>px){
        if(parent.rightNode==nullptr){
            parent.rightNode = &a;
        }
        else{
            createGraph(a, *parent.rightNode);
        }
    }
}

vector<int> preorder(Node a,vector<int>& v){
    v.push_back(a.idx);
    if(a.leftNode!=nullptr)preorder(*a.leftNode,v);
    if(a.rightNode!=nullptr)preorder(*a.rightNode,v);
    return v;
}
vector<int> postorder(Node a,vector<int>& v){
    if(a.leftNode!=nullptr)postorder(*a.leftNode,v);
    if(a.rightNode!=nullptr)postorder(*a.rightNode,v);
    v.push_back(a.idx);
    return v;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node> v;
    int idx=0;
    for(auto node: nodeinfo){
        // node[0] x좌표
        // node[1] y좌표
        idx++;
        v.push_back({idx,node[0],node[1],nullptr,nullptr});
    }
    sort(v.begin(),v.end(),comp);
    
    //먼저 이어주고, 그다음에 순회를해야되는데
    for(int i=1;i<v.size();i++){
        createGraph(v[i],v[0]);
    }
    
    //answer.push_back({v[0].leftNode->x,v[0].leftNode->y});
    vector<int> pv,pv2;
    pv = preorder(v[0],pv);
    pv2 = postorder(v[0],pv2);
    answer.push_back(pv);
    answer.push_back(pv2);
    return answer;
}