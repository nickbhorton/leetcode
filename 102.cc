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
    void helper(TreeNode* node, std::vector<std::vector<int>>& lt, size_t depth)
    {
        if (node == nullptr) {
            return;
        }
        while (lt.size() < depth) {
            lt.push_back({});
        }
        lt[depth].push_back(node->val);
        helper(node->left, lt, depth + 1);
        helper(node->right, lt, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> result{};
        helper(root, result, 0);
        return result;
    }
};
