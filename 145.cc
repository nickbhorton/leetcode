#include <vector>
using std::vector;

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
    void helper(TreeNode* node, std::vector<int>& pot)
    {
        if (node == nullptr) {
            return;
        }
        helper(node->left, pot);
        helper(node->right, pot);
        pot.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root)
    {
        std::vector<int> result{};
        helper(root, result);
        return result;
    }
};
