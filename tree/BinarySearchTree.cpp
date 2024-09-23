#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int a):val{a},left{nullptr}, right(nullptr){};
};

TreeNode* search(TreeNode* root, int num){
    TreeNode* tmp = root;
    while(tmp != nullptr){
        if(num==tmp->val)
            return tmp;
        if(num>tmp->val){
            tmp = tmp->right;
        }
        if(num<tmp->val){
            tmp = tmp->left; 
        }
    }
    return nullptr;
}

void insert(int num, TreeNode*& root){
    if(root == nullptr){
        root = new TreeNode(num);
        return;
    }
    TreeNode* tmp = root, *pre = nullptr;
    while(tmp != nullptr){
        if(tmp->val== num) return;
        pre = tmp;
        if(num < tmp->val)
            tmp = tmp->left; 
        else
            tmp = tmp->right;
    }
    if(pre->val<num)
       { pre->right = new TreeNode(num);
       }

    else
        {pre->left = new TreeNode(num);
            // cout<<"check"<<endl;
        }
}

void remove(int num, TreeNode*& root){
    if(root==nullptr)
        return;
    TreeNode* tmp = root, *pre = nullptr;
    while(tmp!=nullptr){
        if(tmp->val== num){break;}
        pre = tmp;
        if(tmp->val < num)
            tmp = tmp->right; 
        else
            tmp = tmp->left;
    }
    if(tmp==nullptr)
        {return;}
    if(tmp->left==nullptr||tmp->right==nullptr){
        TreeNode* child = tmp->left!=nullptr? tmp->left:tmp->right;
        if(tmp!=root){
            if(pre->left==tmp)
                pre->left = child;
            else
                pre->right = child;
        } 
        else{
            root = child;
        }
        delete tmp;
    }
    else{
        TreeNode* tmp2 = tmp->right;
        while(tmp2->left!=nullptr){
            tmp2 = tmp->left;
        }
        int var = tmp2->val;
        remove(tmp2->val, root);
        tmp->val = var;
    }
}
void levelOrder(TreeNode* root){
    queue<TreeNode*> q;
    TreeNode* tmp = root;
    q.push(tmp);
    while(!q.empty()){
        TreeNode* a = q.front();
        cout<<a->val<<endl;
        q.pop();
        if(a->left!=nullptr) q.push(a->left);
        if(a->right!=nullptr) q.push(a->right);
    }
}
int main(){
    TreeNode* a = new TreeNode{2};
    TreeNode* b = new TreeNode(1);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    a->left = b; a->right = c;
    c->right = d;
    insert(0, a);
    levelOrder(a);
    remove(0,a);
    levelOrder(a);
}
