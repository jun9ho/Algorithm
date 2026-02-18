#include <bits/stdc++.h>

using namespace std;



//트리만들고 순회하면되긴함

bool sorted(vector<int> a, vector<int> b){
    
    if(a[1]==b[1]) return a[0]<b[0];
    return a[1]>b[1];
}

struct Node{
    int index;
    int x;
    int y;
    Node* L;
    Node* R;
};

void insertNode(Node& root, Node& A){
    if(A.x<root.x){
        if(root.L == NULL) root.L= &A;
        else insertNode(*(root.L),A);
    }
    else if(A.x>root.x){
        if(root.R == NULL) root.R=&A;
        else insertNode(*(root.R),A);
    }
    
    return;
}

//preorder Root,L,R
//postorder L,R,Root
void preorder(Node& A,vector<int> &v){
    v.push_back(A.index);
    if(A.L != NULL)preorder(*(A.L),v);
    if(A.R != NULL)preorder(*(A.R),v);
    return;
}
void postorder(Node& A,vector<int> &v){
    if(A.L != NULL)postorder(*(A.L),v);
    if(A.R != NULL)postorder(*(A.R),v);
    v.push_back(A.index);
    return;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<vector<int>> nodei(nodeinfo);
    
    for(int i=0;i<nodeinfo.size();i++){
        nodei[i].push_back(i+1);
    }
    sort(nodei.begin(),nodei.end(),sorted);
    
    Node nn[nodei.size()];
    Node root = {nodei[0][2],nodei[0][0],nodei[0][1],NULL,NULL};
    nn[0]= root;
    for(int i=1;i<nodei.size();i++){
        int x = nodei[i][0];
        int y = nodei[i][1];
        int index = nodei[i][2];
        Node n = {index,x,y,NULL,NULL};
        nn[i]= n;
        insertNode(root,nn[i]);
    }
    vector<int> vv1,vv2;
    preorder(root,vv1);
    postorder(root,vv2);
    answer.push_back(vv1);
    answer.push_back(vv2);
    
    
    return answer;
    
}