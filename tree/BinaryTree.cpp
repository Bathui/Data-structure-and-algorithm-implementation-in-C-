#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int a):val{a},left{nullptr}, right{nullptr}{}
};

// level order, which we used queue to traverse in order of 
vector<int>levelOrder(Node* root){  
    queue<Node*> q;
    vector<int> v;
    q.push(root);
    while(!q.empty()){
        Node* n = q.front();
        v.push_back(n->val);
        q.pop();
        if(n->left!=nullptr) q.push(n->left);
        if(n->right!=nullptr)q.push(n->right);
    }
    return v;
}

int main(){
    Node* a = new Node{1};
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    a->left = b;
    a->right = c;
    b->left = d;
    vector <int> v = levelOrder(a);
    for(int x:v){
        cout<<x<<endl;
    }
}