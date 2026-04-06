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


    void mswap(TreeNode* parent){
        if (parent == nullptr){
            return;
        }
        mswap(parent->left);
        mswap(parent->right);

        // actual swap operation 
        TreeNode* tmp = parent->right;
        parent->right = parent->left;
        parent->left = tmp;
    }

    TreeNode* invertTree(TreeNode* root) {
        mswap(root);
        return root;
    }
};
