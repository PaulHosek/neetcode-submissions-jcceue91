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

    int get_height(TreeNode* parent,bool& balanced){
        if (!parent || !balanced){
            return 0;
        }
        int hl = get_height(parent->left, balanced);
        int hr = get_height(parent->right, balanced);
        if (std::abs(hl - hr) > 1){
            balanced = false;
        }
        return std::max(hl,hr) + 1;

    }

    bool isBalanced(TreeNode* root) {
        bool balanced{true};
        get_height(root, balanced);
        return balanced;



        
    }
};
