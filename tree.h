// #ifndef OP_H
// #define OP_H
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int n);
    // {
    //     val = n;
    //     left = NULL;
    //     right = NULL;
    // };
};

void postOrder(TreeNode*, vector<int>&);
void preOrder(TreeNode*, vector<int>&);
void inOrder(TreeNode*, vector<int>&);

// #endif