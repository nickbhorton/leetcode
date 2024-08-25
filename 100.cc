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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (q != nullptr && p != nullptr) {
            if (p->val == q->val) {
                return isSameTree(p->left, q->left) || isSameTree(p->right, q->right);
            }
            else {
                return false;
            }
        }
        else if (q == nullptr && p == nullptr) {
            return true;
        }
        return false;
    }
};

int main() {
}
