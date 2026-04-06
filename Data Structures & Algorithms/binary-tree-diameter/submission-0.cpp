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

    int find_height(TreeNode* parent,int& diam){
        if (!parent) {
            return 0;
        }
        int hl = find_height(parent->left, diam);
        int hr = find_height(parent->right, diam);

        diam = std::max(hl + hr, diam);
        return std::max(hl, hr) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diam{};
        find_height(root, diam);
        return diam;
    }
};
