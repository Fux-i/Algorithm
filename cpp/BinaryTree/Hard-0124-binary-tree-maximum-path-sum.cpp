#include <algorithm>
#include <climits>
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
public:
    int maxSum = INT_MIN;

    int dfs(TreeNode *root) {
        if (!root) return 0;
        // root is the bridge
        int leftSon = max(dfs(root->left), 0);
        int rightSon = max(dfs(root->right), 0);
        int maxVal = root->val + leftSon + rightSon;
        maxSum = max(maxSum, maxVal);
        // root is in the path
        return root->val + max(leftSon, rightSon);
    }

    int maxPathSum(TreeNode *root) {
        dfs(root);
        return maxSum;
    }
};
