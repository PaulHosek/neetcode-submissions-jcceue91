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
#include <limits>
class Solution {
public:
    void dfs(TreeNode* node, bool& valid, long long min_val, long long max_val) {
        if (!node || !valid) {
            return;
        }
        
        if (node->val <= min_val || node->val >= max_val) {
            valid = false;
            return;
        }
        
        dfs(node->right, valid, node->val, max_val);
        dfs(node->left, valid, min_val, node->val);
    }

    bool isValidBST(TreeNode* root) {
        bool valid{true};
        dfs(root, valid, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
        return valid;
        
    }
};
