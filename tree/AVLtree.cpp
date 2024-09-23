#include <algorithm>
#include <queue>
#include<iostream>
using namespace std;

struct TreeNode{
    int val{};// new c++-11 way of initialization with value zero
    int height = 0;
    TreeNode* left, * right;
    explicit TreeNode(int x):val{x}{}
    TreeNode() = default;
};
int height(TreeNode* node){
    return node!=nullptr? node->height: -1;
}
int balanceFactor(TreeNode* node){
    if (node==nullptr)
        return 0;
    return height(node->left)-height(node->right);
}

void updateHeight(TreeNode* node){
    node->height = max(height(node->left), height(node->right))+1;
}

TreeNode* rightRotation(TreeNode* node){
    TreeNode* child = node->left;
    TreeNode* gran_child = child->right;
    child->right = node;
    node->left = gran_child;
    updateHeight(node);
    updateHeight(child);
    return child;  // the root becomes the child node
}

TreeNode* leftRotation(TreeNode* node){
    TreeNode* child = node->right;
    TreeNode* gran_child = child->left;
    child->left = node;
    node->right = gran_child;
    updateHeight(node);
    updateHeight(child);
    return child;
}

TreeNode* rotate(TreeNode* node){
    int _balanceFactor = balanceFactor(node);
    if(_balanceFactor>1){
        if(balanceFactor(node->left)>=0){
            return rightRotation(node);
        }
        else{
           node->left = leftRotation(node->left);
            return rightRotation(node);
        }
    }
    if(_balanceFactor<-1){
        if(balanceFactor(node->right)<=0){
            return leftRotation(node);
        }
        else{
            node->right = rightRotation(node->right);
            return leftRotation(node);
        }
    }
    return node; // when the node is balanced already

}

TreeNode* insertHelpler(int val, TreeNode*& node){
    if(node == nullptr){
        return new TreeNode(val);
    }
    if(val<node->val){
        node->left=insertHelpler(val, node->left);
    }
    else if (val>node->val){
        node->right = insertHelpler(val, node->right);
    }
    else return node;
    updateHeight(node);
    node = rotate(node);
    return node;
}
void insert(int val, TreeNode*& node){
    node = insertHelpler(val, node);
}


TreeNode* removeHelpler(int val, TreeNode*& node){
    if (node == nullptr)
        return nullptr;
    if(val < node->val)
        node->left = removeHelpler(val, node->left);
    else if(val > node->val)
        node->right = removeHelpler(val, node->right);
    else{
        if(node->left==nullptr||node->right==nullptr){
            TreeNode* child = node->left!=nullptr? node->left:node->right;
            if(child!=nullptr){
                delete node;
                node = child;
            }
            else{
                delete node;
                return nullptr;
            }
        }else{
            TreeNode* temp = node->right;
            while(temp->left!=nullptr){
                temp = temp->left;
            }
            int tempVal = temp->val;
            node->right = removeHelpler(tempVal,node->right);
            node->val = tempVal;
        }
    }
    updateHeight(node);
    node = rotate(node);
    return node;
}
void remove(int val, TreeNode*& node){
    node = removeHelpler(val, node);
}

void levelTraversal(TreeNode* a){
    queue<TreeNode*> q;
    q.push(a);
    while (!q.empty()){
        TreeNode* temp = q.front();
        cout<<temp->val<<endl;
        q.pop();
        if(temp->left!=nullptr){
            q.push(temp->left);
        }
        if(temp->right!=nullptr)
            q.push(temp->right);
    }
}
int main(){
    TreeNode* a = new TreeNode(5);
    
    insert(3,a);
    insert(6,a);
    insert(4,a);
    insert(1,a);
    insert(0,a);
    remove(1,a);
    remove(0,a);

    levelTraversal(a);
}