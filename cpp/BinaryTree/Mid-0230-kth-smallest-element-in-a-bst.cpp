using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int ans;
    bool done = false;
    int count = 0;
    int k_;
public:
    int kthSmallest(TreeNode* root, int k) {
        k_ = k;
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* node) {
        if (!node || done) return;
        dfs(node->left);
        count++;
        if (count == k_) {
            done = true;
            ans = node->val;
        }
        dfs(node->right);
    }
};