#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node*left;
    Node*right;
    Node(int x):val(x),left{nullptr}, right{nullptr}{}
};

void preOrder(Node* root){
    if(root==nullptr) return;
    cout<<root->val<<endl;
    preOrder(root->left);
    preOrder(root->right);
}

void preOrder_it(Node* root){
    cout<<"preorder in iteration"<<endl;
    if(root==nullptr) return;
    stack<Node*> s;
    vector<int> v;
    s.push(root);
    while (!s.empty()) {
        Node* n = s.top();
        v.push_back(n->val);
        s.pop();
        if(n->right!=nullptr) s.push(n->right);
        if(n->left!=nullptr) s.push(n->left);
    }
    for(auto x:v){
        cout<<x<<endl;
    }
}

void inOrder(Node* root){
    if(root==nullptr) return;
    inOrder(root->left);
    cout<<root->val<<endl;
    inOrder(root->right);
}

void inOrder_it(Node* root){
    if(root==nullptr) return;
    stack<Node*> s;
    Node* temp = root;
    while(temp!=nullptr||!s.empty()){
        while(temp!=nullptr){
            s.push(temp);
            temp = temp->left;
        }
        temp= s.top();
        s.pop();
        cout<<temp->val<<endl;
        temp = temp->right;
    }
}

void postOrder(Node* root){
    if(root==nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<endl;
}

void postOrder_it(Node* root){
    Node* tmp = root;
    vector<Node*> v;
    while(tmp!=nullptr&&find(v.begin(), v.end(),tmp)==v.end()){
        if(tmp->left!=nullptr&&find(v.begin(), v.end(),tmp->left)==v.end()){
            tmp = tmp->left;
        }
        else if(tmp->right!=nullptr&&find(v.begin(), v.end(),tmp->right)==v.end()){
            tmp = tmp->right;
        }
        else{
            v.push_back(tmp);
            cout<<tmp->val<<endl;
            tmp = root;
        }
    }
}
int main(){
    Node* a = new Node{1};
    Node*b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    preOrder(a);
    cout<<"-----------"<<endl;
    preOrder_it(a);
    cout<<"-----------"<<endl;
    inOrder(a);
    cout<<"-----------"<<endl;
    inOrder_it(a);
    cout<<"-----------"<<endl;
    postOrder(a);
    cout<<"-----------"<<endl;
    postOrder_it(a);
}