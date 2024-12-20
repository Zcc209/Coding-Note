/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxdepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxdepth(root -> left), maxdepth(root -> right)) + 1;
    }
    void dfs(TreeNode* root, int depth, int& sum, int mxdepth) {
        if (!root) return;
        if (depth == mxdepth) {
            sum += root -> val;
        }
        dfs(root -> left, depth + 1, sum, mxdepth);
        dfs(root -> right, depth + 1, sum, mxdepth);
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int mxdepth = maxdepth(root);
        dfs(root, 1, sum, mxdepth);
        return sum;
    }
};
