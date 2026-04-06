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

// iterative
    int maxDepth(TreeNode* root) {
        if (!root){
            return 0;
        }
        std::queue<TreeNode*> nodes{};
        nodes.push(root);
        int depth{};
        while(!nodes.empty()){
            int qsize = nodes.size();
            for (int i = 0; i < qsize; i++ ){
                TreeNode* parent = nodes.front();
                nodes.pop();
                if (parent->left){
                    nodes.push(parent->left);
                }
                if (parent->right){
                    nodes.push(parent->right);
                }
            }
            depth++;
       }
       return depth;

    }
};
