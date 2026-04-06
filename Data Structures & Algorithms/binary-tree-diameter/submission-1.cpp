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
    int diam{0};
public:
    int dfs_height(TreeNode* parent){
        if (!parent){
            return 0;
        }


        int l = dfs_height(parent->left);
        int r = dfs_height(parent->right);

        diam = std::max(diam, l+r);
        return std::max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs_height(root);
        return diam;
    }
};
