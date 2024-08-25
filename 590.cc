#include <vector>
using std::vector;

class Node
{
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    void helper(Node* node, std::vector<int>& pot)
    {
        if (node == nullptr) {
            return;
        }
        for (auto const& child : node->children) {
            helper(child, pot);
        }
        pot.push_back(node->val);
    }
    vector<int> postorder(Node* root)
    {
        std::vector<int> result{};
        helper(root, result);
        return result;
    }
};
