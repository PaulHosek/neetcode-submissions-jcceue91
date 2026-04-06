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

    std::string serialize(TreeNode* parent){
        if (!parent){
            return "#";
        }

        return "_" + std::to_string(parent->val) + serialize(parent->left) + serialize(parent->right);

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::string r =  serialize(root);
        std::string sR = serialize(subRoot);

        return r.find(sR) != std::string::npos;
        
    }
};
