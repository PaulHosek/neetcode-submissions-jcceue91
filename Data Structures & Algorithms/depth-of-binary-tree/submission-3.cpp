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

    void count_depth(TreeNode* parent, int count, int& res){
        if (parent->left){
            count_depth(parent->left, count+1, res);
        }
        if (parent->right){
            count_depth(parent->right, count+1, res);
        }
        res = max(count, res);
        
    }

    int maxDepth(TreeNode* root) {
        if (!root) {
         return 0;
        }

        int res{};
        count_depth(root, 1, res);
        return res;
        

    }
};
