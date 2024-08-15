#include <vector>
using std::vector;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right)
    {
    }
};

class Solution
{
public:
    void in_order_traveral_helper(TreeNode* root, std::vector<int>& path)
    {
        if (root == nullptr) {
            return;
        }
        in_order_traveral_helper(root->left, path);
        path.push_back(root->val);
        in_order_traveral_helper(root->right, path);
    }
    vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> path{};
        in_order_traveral_helper(root, path);
        return path;
    }
};
