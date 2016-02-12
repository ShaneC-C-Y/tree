#include <vector>

#include "tree.h"


TreeNode::TreeNode( int n ) {
    val = n;
    left = NULL;
    right = NULL;
}

void postOrder(TreeNode* current, vector<int>& ans){
    if(current->left)
        postOrder(current->left, ans);
    if(current->right)
        postOrder(current->right, ans);

    ans.push_back(current->val);
    return;
}

void preOrder(TreeNode* current, vector<int>& ans){
    ans.push_back(current->val);
    if(current->left)
        preOrder(current->left, ans);
    if(current->right)
        preOrder(current->right, ans);

    return;
}

void inOrder(TreeNode* current, vector<int>& ans){

}