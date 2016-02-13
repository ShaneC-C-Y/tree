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

void postOrder_recursive(TreeNode*, vector<int>&);
void preOrder_recursive(TreeNode*, vector<int>&);
void inOrder_recursive(TreeNode*, vector<int>&);

void levelOrder_recursive(TreeNode*, vector<int>&);
void levelOrder(TreeNode*, vector<int>&);

// void BFS(TreeNode*, vector<int>&);
// void DFS(TreeNode*, vector<int>&);


// #endif