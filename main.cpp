#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

int main(){

    // construct the tree
    TreeNode a(3), b(2), c(4), d(5), e(6);
    TreeNode *root = &a;
    root->right = &b;
    root->left = &c;
    root->right->left = &d;
    // root->left->right = &e;

    vector<int> ans;

    // show order
    preOrder(root, ans);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
