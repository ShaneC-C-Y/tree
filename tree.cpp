#include <vector>
#include <stack>
#include <queue>
// #include <iostream>

#include "tree.h"


TreeNode::TreeNode( int n ) {
    val = n;
    left = NULL;
    right = NULL;
}

void postOrder_recursive(TreeNode* current, vector<int>& ans){
    if(current->left)
        postOrder(current->left, ans);
    if(current->right)
        postOrder(current->right, ans);

    ans.push_back(current->val);
    return;
}

void preOrder_recursive(TreeNode* current, vector<int>& ans){
    ans.push_back(current->val);
    if(current->left)
        preOrder(current->left, ans);
    if(current->right)
        preOrder(current->right, ans);

    return;
}

void inOrder_recursive(TreeNode* current, vector<int>& ans){

}

void postOrder(TreeNode* root, vector<int>& ans){
    stack<TreeNode*> history;
    TreeNode* ptr = root;
    TreeNode* lastNode = NULL;

    while(ptr || !history.empty()) {
        if(ptr != NULL) {    
            history.push(ptr);
            ptr = ptr->left;
        }
        else {
            if(history.top()->right != NULL && history.top()->right != lastNode){
                ptr = history.top()->right;   
            }        
            else{        
                ans.push_back(history.top()->val);
                lastNode = history.top();
                history.pop(); 
            }
        }
    }
}

void preOrder(TreeNode* root, vector<int>& ans){
    stack<TreeNode*> history;
    TreeNode* ptr = root;
    while(ptr || !history.empty()) {
        if(ptr != NULL) {
            ans.push_back(ptr->val);
            history.push(ptr);
            ptr = ptr->left;
        }
        else {
            ptr = history.top();
            history.pop();
            ptr = ptr->right;            
        }
    }
}

void inOrder(TreeNode* root, vector<int>& ans){
    stack<TreeNode*> history;
    TreeNode* ptr = root;
    while(ptr || !history.empty()) {
        if(ptr != NULL) {
            history.push(ptr);
            ptr = ptr->left;
        }
        else{   
            ptr = history.top();
            history.pop();
            ans.push_back(ptr->val);
            ptr = ptr->right;
        }
    }
}

void golevel(TreeNode* current, int layer, vector<vector<int> >& matrix){
    if(current->left != NULL)
        golevel(current->left, layer+1, matrix);
    if(current->right != NULL)
        golevel(current->right, layer+1, matrix);
    if(matrix.size() <= layer)
        matrix.resize(2*matrix.size());
    matrix[layer].push_back(current->val);
    return;
}

void levelOrder_recursive(TreeNode* root, vector<int>& ans){
    vector<vector<int> > matrix;
    matrix.resize(2);
    int layer = 0;
    golevel(root, layer, matrix);
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++)
            ans.push_back(matrix[i][j]);
    }
}

void levelOrder(TreeNode* root, vector<int>& ans){
    queue<TreeNode*> myqueue;
    myqueue.push(root);
    TreeNode* ptr;
    while(!myqueue.empty()){
        ptr = myqueue.front();
        myqueue.pop();        
        ans.push_back(ptr->val);

        if(ptr->left)
            myqueue.push(ptr->left);
        if(ptr->right)
            myqueue.push(ptr->right);
    }
}


