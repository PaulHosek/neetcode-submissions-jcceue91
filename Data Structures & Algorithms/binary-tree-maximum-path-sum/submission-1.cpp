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
    int maxPathSum(TreeNode* root) {
        int res{root->val};
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* parent, int& res){
        if (!parent){
            return 0;
        }

        int lmax = std::max(0, dfs(parent->left, res));
        int rmax = std::max(0, dfs(parent->right, res));

        res = std::max(res, parent->val + lmax + rmax);
        return std::max(lmax + parent->val, rmax + parent->val);
    }
};
