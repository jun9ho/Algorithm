#include <bits/stdc++.h>

using namespace std;

struct Node{
    int idx;
    int x;
    int y;
    Node * left;
    Node * right;
};

bool sorted(Node a,Node b){
    if(a.y==b.y){
        return a.x<b.x;
    }
    return a.y>b.y;
}

void createTree(Node& root,Node& cur){
    
    if(root.x>cur.x){//왼
        if(root.left == NULL)root.left = &cur;
        else createTree(*root.left,cur);
    }
    else{//오
        if(root.right == NULL) root.right = &cur;
        else createTree(*root.right, cur);
    }
    return;
}

void preorder(Node cur,vector<int>& v){
    v.push_back(cur.idx);
    if(cur.left  !=  NULL)preorder(*cur.left,v);
    if(cur.right !=  NULL)preorder(*cur.right,v);
}
void postorder(Node cur,vector<int>& v){
    if(cur.left  !=  NULL)postorder(*cur.left,v);
    if(cur.right !=  NULL)postorder(*cur.right,v);
    v.push_back(cur.idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    int n = nodeinfo.size();
    vector<Node> v(n);
    
    for(int i=0;i<n;i++){
        v[i].idx= i+1;
        v[i].x = nodeinfo[i][0];
        v[i].y = nodeinfo[i][1];
        v[i].left =  NULL;
        v[i].right = NULL;
    }
    
    sort(v.begin(),v.end(),sorted);
    
    for(int i=1;i<n;i++){
        createTree(v[0],v[i]);
    }
    vector<int> pre,post;
    preorder(v[0],pre);
    postorder(v[0],post);
    
    
    return {pre,post};
}